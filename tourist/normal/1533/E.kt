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
    var n = readInt()
    var a = readInts().toMutableList()
    var b = readInts().toMutableList()
    a.sort()
    b.sort()
    val inf = 1.01e9.toInt()
    var pref = IntArray(n + 1) {-inf}
    for (i in 0 until n) {
        pref[i + 1] = maxOf(pref[i], b[i] - a[i])
    }
    var suf = IntArray(n + 1) {-inf}
    for (i in n - 1 downTo 0) {
        suf[i] = maxOf(suf[i + 1], b[i + 1] - a[i])
    }
    var m = readInt()
    var c = readInts()
    var res = IntArray(m)
    for (i in 0 until m) {
        var pos = a.binarySearch(c[i])
        if (pos < 0) {
            pos = -pos - 1
        }
        res[i] = maxOf(maxOf(pref[pos], suf[pos]), b[pos] - c[i])
    }
    println(res.joinToString(" "))
}