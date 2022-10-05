import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        val lcp = Array(n + 1) { IntArray(n + 1) }
        for (j in n - 1 downTo 0) {
            for (k in n - 1 downTo 0) {
                if (s[j] == s[k]) {
                    lcp[j][k] = lcp[j + 1][k + 1] + 1
                }
            }
        }
        val dp = IntArray(n)
        for (j in 0 until n) {
            dp[j] = n - j
            for (k in 0 until j) {
                val l = lcp[j][k]
                if (j + l < n && s[k + l] < s[j + l]) {
                    dp[j] = max(dp[j], dp[k] + n - j - l)
                }
            }
        }
        println(dp.max()!!)
    }
}