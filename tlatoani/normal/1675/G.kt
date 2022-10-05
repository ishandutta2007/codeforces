import kotlin.math.abs
import kotlin.math.min

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val pancakes = readLine()!!.split(" ").map { it.toInt() }.reversed()
    val dp = Array(n + 1) { Array(m + 1) { IntArray((4 * m) + 1) { 2 * n * m } } }
    dp[0][0][2 * m] = 0
    for (j in 1..n) {
        val stack = pancakes[j - 1]
        for (k in 0..m) {
            for (d in 0..4 * m) {
                val nd = d + (stack - k)
                if (nd in 0..4 * m) {
                    dp[j][k][nd] = dp[j - 1][k][d]
                }
            }
        }
        for (k in 0 until m) {
            for (d in 1..4 * m) {
                dp[j][k + 1][d - 1] = min(dp[j][k + 1][d - 1], dp[j][k][d])
            }
        }
        for (k in 0..m) {
            for (d in 0..4 * m) {
                dp[j][k][d] += abs(d - (2 * m))
            }
        }
    }
    println(dp[n].map { it[2 * m] }.min()!!)
}