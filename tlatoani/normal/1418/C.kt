import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val bosses = ("0 " + jin.readLine()).split(" ").map { it.toInt() }
        val dp = Array(2) { IntArray(n + 1) }
        dp[1][0] = 115115115
        dp[0][1] = 115115115
        dp[0][0] = 0
        dp[1][1] = bosses[1]
        for (j in 2..n) {
            dp[0][j] = min(dp[1][j - 1], dp[1][j - 2])
            dp[1][j] = min(dp[0][j - 1] + bosses[j], dp[0][j - 2] + bosses[j] + bosses[j - 1])
        }
        out.appendln(min(dp[0][n], dp[1][n]))
    }
    print(out)
}