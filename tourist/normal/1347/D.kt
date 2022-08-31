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
        var L = 0
        var R = n
        var Ls = 0
        var Rs = 0
        var last = 0
        var iter = 0
        while (L < R) {
            var cur = 0
            if (iter % 2 == 0) {
                while (L < R && cur <= last) {
                    cur += a[L]
                    L += 1
                }
                Ls += cur
            } else {
                while (L < R && cur <= last) {
                    R -= 1
                    cur += a[R]
                }
                Rs += cur
            }
            last = cur
            iter += 1
        }
        println("${iter} ${Ls} ${Rs}")
    }
}