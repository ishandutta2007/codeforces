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
        var (n, k) = readInts()
        var ans = 0
        for (i in 0 until n) {
            var (l, r) = readInts()
            if (k in l..r) {
                ans = maxOf(ans, r - k + 1)
            }
        }
        println(ans)
    }
}