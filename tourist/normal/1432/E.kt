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
    var t = readInt()
    for (i in 0 until t) {
        var (n, k) = readLongs()
        var s = readLn()
        var res = CharArray(n.toInt())
        var pos = 0
        var ones = 0
        for (c in s) {
            if (c == '0') {
                if (k >= ones) {
                    res[pos] = '0'
                    pos += 1
                    k -= ones
                } else {
                    for (i in 0 until ones - k) {
                        res[pos] = '1'
                        pos += 1
                    }
                    res[pos] = '0'
                    pos += 1
                    for (i in 0 until k) {
                        res[pos] = '1'
                        pos += 1
                    }
                    k = 0
                    ones = 0
                }
            } else {
                ones += 1
            }
        }
        for (i in 0 until ones) {
            res[pos] = '1'
            pos += 1
        }
        myAssert(pos == n.toInt())
        println(res.joinToString(""))
    }
}