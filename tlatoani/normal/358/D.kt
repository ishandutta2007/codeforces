import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val a = IntArray(n) { jin.nextInt() }
    val b = IntArray(n) { jin.nextInt() }
    val c = IntArray(n) { jin.nextInt() }
    val dp = Array(2) { IntArray(n) }
    // 0 = before
    // 1 = after
    dp[0][0] = a[0]
    dp[1][0] = b[0]
    for (j in 1 until n) {
        dp[0][j] = max(dp[0][j - 1] + b[j], dp[1][j - 1] + a[j])
        dp[1][j] = max(dp[0][j - 1] + c[j], dp[1][j - 1] + b[j])
    }
    println(dp[0][n - 1])
}