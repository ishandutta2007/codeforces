import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val a = " " + jin.readLine()
    val b = " " + jin.readLine()
    val dp = Array(n + 1) { IntArray(m + 1) }
    for (j in 0..n) {
        for (k in 0..m) {
            if (j > 0) {
                dp[j][k] = max(dp[j][k], dp[j - 1][k] - 1)
            }
            if (k > 0) {
                dp[j][k] = max(dp[j][k], dp[j][k - 1] - 1)
            }
            if (j > 0 && k > 0 && a[j] == b[k]) {
                dp[j][k] = max(dp[j][k], dp[j - 1][k - 1] + 2)
            }
        }
    }
    println(dp.map { it.max()!! }.max()!!)
}