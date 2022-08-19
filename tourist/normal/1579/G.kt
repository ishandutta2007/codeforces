import java.math.BigInteger
import java.util.*

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts()
        var low = 1
        var high = 2 * a.maxOrNull()!!
        while (low < high) {
            var mid = (low + high) shr 1
            val all = BigInteger.valueOf(2).pow(mid).subtract(BigInteger.ONE)
            var x = all
            for (len in a) {
                x = x.shiftLeft(len).or(x.shiftRight(len)).and(all)
            }
            if (x.compareTo(BigInteger.ZERO) == 0) {
                low = mid + 1
            } else {
                high = mid
            }
        }
        println(low - 1)
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }