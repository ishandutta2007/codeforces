import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val red = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
        val m = jin.readLine().toInt()
        val blue = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
        val sums = Array(n + 1) { IntArray(m + 1) }
        val dp = Array(n + 1) { IntArray(m + 1) }
        for (x in 0..n) {
            for (y in 0..m) {
                if (x > 0) {
                    sums[x][y] = sums[x - 1][y] + red[x]
                } else if (y > 0) {
                    sums[x][y] = sums[x][y - 1] + blue[y]
                }
                dp[x][y] = maxOf(sums[x][y], if (x > 0) dp[x - 1][y] else 0, if (y > 0) dp[x][y - 1] else 0)
            }
        }
        out.appendln(dp[n][m])
    }
    print(out)
}