import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val platforms = (listOf(0) + readLine()!!.split(" ").map { it.toInt() }).withIndex().map { (j, a) -> j + a }
        val dp = Array(n + 1) { IntArray(n + 1) { n } }
        val prefixes = Array(n + 1) { IntArray(n + 1) { n } }
        dp[0][1] = 0
        for (j in 1..n) {
            var curr = 0
            for (k in j - 1 downTo 1) {
                if (platforms[k] >= j) {
                    dp[platforms[k]][j] = min(dp[platforms[k]][j], curr + prefixes[k][j - 1])
                    curr++
                }
            }
            prefixes[j][0] = dp[0][j]
            for (k in 1..n) {
                prefixes[j][k] = min(prefixes[j][k - 1], dp[k][j])
            }
        }
        println(prefixes[n][n])
    }
}