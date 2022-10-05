import kotlin.math.abs
import kotlin.math.max

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tags = readLine()!!.split(" ").map { it.toInt() }
        val scores = readLine()!!.split(" ").map { it.toLong() }
        val dp = LongArray(n)
        for (j in 0 until n) {
            for (k in j - 1 downTo 0) {
                if (tags[j] != tags[k]) {
                    val x = dp[k]
                    val y = dp[j]
                    dp[k] = max(dp[k], y + abs(scores[k] - scores[j]))
                    dp[j] = max(dp[j], x + abs(scores[j] - scores[k]))
                }
            }
        }
        println(dp.max())
    }
}