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
        var (n, x, y) = readInts()
        if (x > y) {
            x = y.also {y = x}
        }
        var low = maxOf(x - 1, n - y)
        var high = 2 * n
        while (low < high) {
            var mid = (low + high) shr 1
            var L = maxOf((mid - (x - 1)) / 2, mid - 2 * (x - 1))
            var R = maxOf((mid - (n - y)) / 2, mid - 2 * (n - y))
            if (L + R >= y - x - 1) {
                high = mid
            } else {
                low = mid + 1
            }
        }
        println(low)
    }
}