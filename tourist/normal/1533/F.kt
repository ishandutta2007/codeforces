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
    var s = readLn()
    var n = s.length
    var pref = IntArray(n + 1)
    for (i in 0 until n) {
        pref[i + 1] = pref[i] + (if (s[i] == '1') 1 else 0)
    }
    var res = IntArray(n)
    for (k in 1..n) {
        var pos = 0
        while (pos < n) {
            res[k - 1] += 1
            var low = pos
            var high = n
            while (low < high) {
                var mid = (low + high + 1) shr 1
                var len = mid - pos
                var c1 = pref[mid] - pref[pos]
                var c0 = len - c1
                if (c0 <= k || c1 <= k) {
                    low = mid
                } else {
                    high = mid - 1
                }
            }
            pos = low
        }
    }
    println(res.joinToString(" "))
}