import kotlin.math.max
import kotlin.math.min

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val numbers = listOf(0) + readLine()!!.split(" ").map { it.toInt() }.sorted()
    val dp = Array(n + 1) { IntArray(k + 1) }
    for (j1 in 1..n) {
        for (j2 in 0..k) {
            dp[j1][j2] = dp[j1 - 1][j2]
            var pos = dp[j1][j2]
            for (lambda in 1..min(j1 / 2, j2)) {
                pos -= dp[j1 - (2 * (lambda - 1))][j2 - (lambda - 1)]
                pos += dp[j1 - (2 * lambda)][j2 - lambda]
                pos += 2 * numbers[j1 - lambda + 1]
                pos -= numbers[j1 - (2 * lambda) + 2]
                pos -= numbers[j1 - (2 * lambda) + 1]
                dp[j1][j2] = max(dp[j1][j2], pos)
            }
        }
    }
    println(dp[n][k])
}