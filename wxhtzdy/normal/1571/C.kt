import java.util.Vector
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
    var can = Vector<Int>()
    for (i in 0 until 200005) can.addAll(listOf(1))
    var t = readInt()
    for (i in 0 until t) {
        var nn = readInt()
        var s = Array<String>(nn) {""}
        var t = Array<String>(nn) {""}
        var x = Array<String>(nn) {""}
        var mxK = 10000000
        for (j in 0 until nn) {
            var (ss, tt, xx) = readStrings()
            s[j] = ss
            t[j] = tt
            x[j] = xx
            if (x[j] == "1") mxK = minOf(mxK, minOf(s[j].length, t[j].length) + 2)
        }
        for (j in 0 until mxK) can[j] = 1 
        for (j in 0 until nn) {
            var n = s[j].length
            var m = t[j].length
            var diff = false
            for (k in 0 until minOf(n, m) + 1) {
                if (k > 0) {
                    if (s[j][n - k] != t[j][m - k]) {
                        diff = true
                    }
                }
                if (!diff) {
                    if (x[j] == "0") can[k] = 0
                } else {
                    if (x[j] == "1") can[k] = 0
                }
            }
            if (x[j] == "1") {
                for (j in minOf(n, m) + 1 until mxK) can[j] = 0
            }
        }
        var cnt = 0
        for (j in 0 until mxK) {
            if (can[j] == 1) cnt = cnt + 1
        }
        println(cnt)
        var res = IntArray(cnt)
        var nxt = 0
        for (j in 0 until mxK) {
            if (can[j] == 1) {
                res[nxt] = j
                nxt = nxt + 1
            }
        }
        println(res.joinToString(" "))
    }
}