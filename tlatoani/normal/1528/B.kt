const val MOD = 998244353L

fun main() {
    val n = readLine()!!.toInt()
    val dp = LongArray(n + 1)
    for (f in 1..n) {
        for (k in f..n step f) {
            dp[k]++
        }
    }
    var prev = 0L
    for (k in 1..n) {
        dp[k] += prev
        if (dp[k] >= MOD) {
            dp[k] -= MOD
        }
        prev += dp[k]
        if (prev >= MOD) {
            prev -= MOD
        }
    }
    println(dp[n])
}