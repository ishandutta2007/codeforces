fun main() {
    val line = readLine()!!.split(" ")
    val n = line[0].toInt()
    val mod = line[1].toLong()
    val limit = (n * (n - 1)) / 2
    val dp = Array(n + 1) { LongArray(limit + 1) }
    dp[0][0] = 1L
    var answer = 0L
    for (k in 1..n) {
        for (j in 0..limit) {
            if (j > 0) {
                dp[k][j] += dp[k][j - 1]
            }
            dp[k][j] += dp[k - 1][j]
            if (j >= k) {
                dp[k][j] -= dp[k - 1][j - k]
            }
            if (dp[k][j] >= mod) {
                dp[k][j] -= mod
            }
            if (dp[k][j] < 0L) {
                dp[k][j] += mod
            }
        }
        var here = 0L
        var curr = 0L
        var addend2 = 0L
        var addend1 = 0L
        for (j in 0..limit) {
            here += dp[k - 1][j] * curr
            here %= mod
            curr += addend2
            if (curr >= mod) {
                curr -= mod
            }
            if (j >= k) {
                addend1 -= dp[k - 1][j - k]
            }
            addend1 += dp[k - 1][j]
            if (addend1 >= mod) {
                addend1 -= mod
            }
            if (addend1 < 0L) {
                addend1 += mod
            }
            addend2 += k.toLong() * dp[k - 1][j]
            addend2 -= addend1
            addend2 += mod
            addend2 %= mod
        }
        for (k2 in k + 1..n) {
            here *= k2.toLong()
            here %= mod
        }
        answer += here
        answer %= mod
    }
    println(answer)
}