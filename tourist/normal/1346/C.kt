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
        var (n, k, x, y) = readInts()
        var a = readInts().sorted()
        var ans = 0
        for (v in a) {
            if (v > k) {
                ans += x
            }
        }
        var sum = 0L
        for (v in a) {
            sum += v
        }
        var limit = n.toLong() * k
        var other = y
        for (i in 0 until n) {
            if (sum > limit) {
                sum -= a[n - i - 1]
                other += x
            }
        }
        println(minOf(ans, other))
    }
}