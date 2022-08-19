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
        var (n, s) = readLongs()
        var low = (s + n - 1L) / n
        var high = s
        while (low < high) {
            var mid = (low + high + 1L) shr 1
            var sum = mid
            var cur = mid
            var days = 1L
            while (days < n && cur > 1L) {
                days += 1L
                cur = (cur + 1L) / 2L
                sum += cur
            }
            sum += n - days
            if (sum > s) {
                high = mid - 1L
            } else {
                low = mid
            }
        }
        println(low)
    }
}