import java.io.BufferedReader
import java.io.InputStreamReader
import java.math.BigInteger

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val ap = jin.readLine().split(" ").map { it.toLong() }.sortedDescending()
    val bp = jin.readLine().split(" ").map { it.toLong() }.sortedDescending()
    val totalA = BigInteger.valueOf(ap.sum())
    val totalB = BigInteger.valueOf(bp.sum())
    var answer = BigInteger.valueOf(Long.MAX_VALUE) * BigInteger.valueOf(Long.MAX_VALUE)
    var curr = BigInteger.ZERO
    for (j in n - 1 downTo 0) {
        val pos = (totalB * BigInteger.valueOf((j + 1).toLong())) + curr
        if (pos < answer) {
            answer = pos
        }
        curr += BigInteger.valueOf(ap[j])
    }
    curr = BigInteger.ZERO
    for (j in m - 1 downTo 0) {
        val pos = (totalA * BigInteger.valueOf((j + 1).toLong())) + curr
        if (pos < answer) {
            answer = pos
        }
        curr += BigInteger.valueOf(bp[j])
    }
    println(answer)
}