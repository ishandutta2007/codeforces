import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
        val ofColor = Array(n + 1) { mutableListOf<Int>() }
        for (j in n downTo 1) {
            ofColor[ay[j]].add(j)
        }
        val dp = Array(n + 2) { IntArray(n + 2) }
        for (l in n downTo 1) {
            for (r in l + 1..n) {
                dp[l][r] = maxOf(dp[l][r], dp[l + 1][r], dp[l][r - 1])
                if (ay[l] == ay[r]) {
                    dp[l][r] = max(dp[l][r], 1 + dp[l + 1][r - 1])
                }
                for (x in ofColor[ay[r]]) {
                    if (x <= r) {
                        break
                    }
                    dp[l][x] = max(dp[l][x], dp[l][r] + dp[r][x])
                }
            }
        }
        println((n - 1) - dp[1][n])
    }
}