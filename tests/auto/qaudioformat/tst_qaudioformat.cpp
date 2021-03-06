/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include <QtTest/QtTest>
#include <QtCore/qlocale.h>
#include <qaudioformat.h>

#include <QStringList>
#include <QList>


class tst_QAudioFormat : public QObject
{
    Q_OBJECT

public:
    tst_QAudioFormat(QObject* parent=0) : QObject(parent) {}

private slots:
    void checkNull();
    void checkFrequency();
    void checkChannels();
    void checkSampleSize();
    void checkCodec();
    void checkByteOrder();
    void checkSampleType();
    void checkEquality();
    void checkAssignment();
};

void tst_QAudioFormat::checkNull()
{
    // Default constructed QAudioFormat is invalid.
    QAudioFormat    audioFormat0;
    QVERIFY(!audioFormat0.isValid());

    // validity is transferred
    QAudioFormat    audioFormat1(audioFormat0);
    QVERIFY(!audioFormat1.isValid());

    audioFormat0.setFrequency(44100);
    audioFormat0.setChannels(2);
    audioFormat0.setSampleSize(16);
    audioFormat0.setCodec("audio/pcm");
    audioFormat0.setSampleType(QAudioFormat::SignedInt);
    QVERIFY(audioFormat0.isValid());
}

void tst_QAudioFormat::checkFrequency()
{
    QAudioFormat    audioFormat;
    audioFormat.setFrequency(44100);
    QVERIFY(audioFormat.frequency() == 44100);
}

void tst_QAudioFormat::checkChannels()
{
    QAudioFormat    audioFormat;
    audioFormat.setChannels(2);
    QVERIFY(audioFormat.channels() == 2);
}

void tst_QAudioFormat::checkSampleSize()
{
    QAudioFormat    audioFormat;
    audioFormat.setSampleSize(16);
    QVERIFY(audioFormat.sampleSize() == 16);
}

void tst_QAudioFormat::checkCodec()
{
    QAudioFormat    audioFormat;
    audioFormat.setCodec(QString::fromLatin1("audio/pcm"));
    QVERIFY(audioFormat.codec() == QString::fromLatin1("audio/pcm"));
}

void tst_QAudioFormat::checkByteOrder()
{
    QAudioFormat    audioFormat;
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    QVERIFY(audioFormat.byteOrder() == QAudioFormat::LittleEndian);
}

void tst_QAudioFormat::checkSampleType()
{
    QAudioFormat    audioFormat;
    audioFormat.setSampleType(QAudioFormat::SignedInt);
    QVERIFY(audioFormat.sampleType() == QAudioFormat::SignedInt);
}

void tst_QAudioFormat::checkEquality()
{
    QAudioFormat    audioFormat0;
    QAudioFormat    audioFormat1;

    // Null formats are equivalent
    QVERIFY(audioFormat0 == audioFormat1);
    QVERIFY(!(audioFormat0 != audioFormat1));

    // on filled formats
    audioFormat0.setFrequency(8000);
    audioFormat0.setChannels(1);
    audioFormat0.setSampleSize(8);
    audioFormat0.setCodec("audio/pcm");
    audioFormat0.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat0.setSampleType(QAudioFormat::UnSignedInt);

    audioFormat1.setFrequency(8000);
    audioFormat1.setChannels(1);
    audioFormat1.setSampleSize(8);
    audioFormat1.setCodec("audio/pcm");
    audioFormat1.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat1.setSampleType(QAudioFormat::UnSignedInt);

    QVERIFY(audioFormat0 == audioFormat1);
    QVERIFY(!(audioFormat0 != audioFormat1));

    audioFormat0.setFrequency(44100);
    QVERIFY(audioFormat0 != audioFormat1);
    QVERIFY(!(audioFormat0 == audioFormat1));
}

void tst_QAudioFormat::checkAssignment()
{
    QAudioFormat    audioFormat0;
    QAudioFormat    audioFormat1;

    audioFormat0.setFrequency(8000);
    audioFormat0.setChannels(1);
    audioFormat0.setSampleSize(8);
    audioFormat0.setCodec("audio/pcm");
    audioFormat0.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat0.setSampleType(QAudioFormat::UnSignedInt);

    audioFormat1 = audioFormat0;
    QVERIFY(audioFormat1 == audioFormat0);

    QAudioFormat    audioFormat2(audioFormat0);
    QVERIFY(audioFormat2 == audioFormat0);
}

QTEST_MAIN(tst_QAudioFormat)

#include "tst_qaudioformat.moc"
