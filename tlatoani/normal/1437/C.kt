import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val times = listOf(0) + jin.readLine().split(" ").map { it.toInt() }.sorted()
        val dp = Array(2 * n) { IntArray(n + 1) { 115115 } }
        dp[0][0] = 0
        for (t in 1 until 2 * n) {
            for (j in 0..n) {
                dp[t][j] = dp[t - 1][j]
                if (j > 0) {
                    dp[t][j] = min(dp[t][j], dp[t - 1][j - 1] + abs(t - times[j]))
                }
            }
        }
        println(dp.last()[n])
    }
}