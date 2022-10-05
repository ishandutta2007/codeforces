import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val numbers = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
        val dp = Array(n + 1) { Array(n + 1) { -3000 } }
        dp[0][0] = 0
        for (j in 1..n) {
            for (d in 0..n) {
                dp[j][d] = max(dp[j][d], dp[j - 1][d] + (if (j - d == numbers[j]) 1 else 0))
                if (d > 0) {
                    dp[j][d] = max(dp[j][d], dp[j - 1][d - 1])
                }
            }
            //println(dp[j].contentToString())
        }
        println((0..n).firstOrNull { d -> dp[n][d] >= k } ?: -1)
    }
}