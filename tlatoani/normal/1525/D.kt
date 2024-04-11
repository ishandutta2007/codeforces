import kotlin.math.abs
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val ocupado = listOf(false) + readLine()!!.split(" ").map { it == "1" }
    val dp = Array(n + 1) { IntArray((2 * n) + 1) { 1000000000 } }
    dp[0][n] = 0
    for (x in 1..n) {
        if (ocupado[x]) {
            for (y in 1..2 * n) {
                dp[x][y] = dp[x - 1][y - 1] + abs((y - 1) - n)
            }
        } else {
            for (y in 0..2 * n) {
                dp[x][y] = dp[x - 1][y] + abs(y - n)
            }
            for (y in 0 until 2 * n) {
                dp[x][y] = min(dp[x][y], dp[x - 1][y + 1] + abs((y + 1) - n))
            }
        }
    }
    println(dp[n][n])
}