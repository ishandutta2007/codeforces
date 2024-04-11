import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val rows = Array(2) { LongArray(n) { jin.nextLong()} }
    var dp = LongArray(2)
    for (i in 0 until n) {
        dp = LongArray(2) { j -> max(dp[j], dp[1 - j] + rows[j][i]) }
    }
    println(max(dp[0], dp[1]))
}