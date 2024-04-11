import java.lang.AssertionError
import java.util.*

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
    var (n, k, x) = readInts()
    var a = readInts()
    var low = 0L
    var high = 1e11.toLong()
    while (low < high) {
        var mid = (low + high) shr 1
        var removed = 0
        var s = TreeSet<Long>()
        var sum = 0L
        for (i in 0 until n) {
            s.add((a[i].toLong() shl 32) + i)
            sum += a[i]
            while (sum > mid) {
                removed += 1
                sum -= s.last() shr 32
                s.pollLast()
            }
            if (s.size == x) {
                s.clear()
                sum = 0L
            }
        }
        if (removed <= k) {
            high = mid
        } else {
            low = mid + 1
        }
    }
    println(low)
}