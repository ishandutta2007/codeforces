import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val dp = Array(n + 1) { IntArray(2001) { 2000 } }
        dp[0][0] = 0
        val tokenizer = StringTokenizer(readLine()!!)
        for (j in 1..n) {
            val x = tokenizer.nextToken().toInt()
            for (y in 0..2000) {
                var a = max(0, y - x)
                var b = dp[j - 1][y] + x
                if (a <= 2000) {
                    dp[j][a] = min(dp[j][a], b)
                }
                a = max(0, dp[j - 1][y] - x)
                b = y + x
                if (a <= 2000) {
                    dp[j][a] = min(dp[j][a], b)
                }
            }
        }
        var answer = 2000
        for (y in 0..2000) {
            answer = min(answer, y + dp[n][y])
        }
        println(answer)
    }
}