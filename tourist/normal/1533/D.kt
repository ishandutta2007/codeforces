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
    var (n, m) = readInts()
    var s = Array<String>(n) {""}
    for (i in 0 until n) {
        s[i] = readLn()
    }
    s.sort()
    var t = readInt()
    for (i in 0 until t) {
        var w = readLn()
        var ans = 0
        for (j in 0 until m + 1) {
            if (j > 0 && w[j] == w[j - 1]) {
                continue
            }
            var z = w.substring(0, j) + w.substring(j + 1)
            if (s.binarySearch(z) >= 0) {
                ans += 1
            }
        }
        println(ans)
    }
}