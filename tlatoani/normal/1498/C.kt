const val MOD = 1000000007L

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val dp = Array(k) { LongArray(n + 2) }
        dp[0][0] = 1L
        for (j in 1 until k) {
            if (j % 2 == 1) {
                for (j2 in 1..n) {
                    dp[j][j2] = (dp[j][j2 - 1] + dp[j - 1][j2 - 1]) % MOD
                }
            } else {
                for (j2 in n downTo 1) {
                    dp[j][j2] = (dp[j][j2 + 1] + dp[j - 1][j2 + 1]) % MOD
                }
            }
        }
        println(dp.map { it.sum() }.sum() % MOD)
    }
}