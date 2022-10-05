fun main() {
    val n = readLine()!!.toLong()
    val dp = LongArray(100000)
    dp[0] = 1L
    dp[1] = 2L
    for (j in 2..100000) {
        dp[j] = dp[j - 1] + dp[j - 2]
        if (dp[j] > n) {
            println(j - 1)
            return
        }
    }
}