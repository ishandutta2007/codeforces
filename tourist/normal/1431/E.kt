import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    var tt = readInt()
    for (qq in 0 until tt) {
        var n = readInt()
        var a = readInts()
        var b = readInts()
        var ans = -1
        var bestShift = -1
        for (shift in 0 until n) {
            var cur = 1e9.toInt()
            for (i in 0 until n) {
                cur = minOf(cur, kotlin.math.abs(b[(i + shift) % n] - a[i]))
            }
            if (cur > ans) {
                ans = cur
                bestShift = shift
            }
        }
        var ret = IntArray(n)
        for (i in 0 until n) {
            ret[i] = (i + bestShift) % n + 1
        }
        println(ret.joinToString(" "))
    }
}