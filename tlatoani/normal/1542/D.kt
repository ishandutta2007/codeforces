const val MOD = 998244353L

fun main() {
    val n = readLine()!!.toInt()
    val s = Array(n) {
        val line = readLine()!!.split(" ")
        if (line[0] == "+") {
            line[1].toInt()
        } else {
            0
        }
    }
    var answer = 0L
    for (r in 0 until n) {
        if (s[r] > 0) {
            val amt = (0 until n).count { s[it] > 0 && (s[it] < s[r] || (s[it] == s[r] && it < r)) }
            val dp = LongArray(amt + 1)
            dp[0] = 1L
            for (j in 0 until n) {
                if (j != r) {
                    val x = s[j]
                    if (x == 0) {
                        if (j < r) {
                            dp[0] *= 2L
                            if (dp[0] >= MOD) {
                                dp[0] -= MOD
                            }
                        }
                        for (k in 0 until amt) {
                            dp[k] += dp[k + 1]
                            if (dp[k] >= MOD) {
                                dp[k] -= MOD
                            }
                        }
                    } else if (x < s[r] || (x == s[r] && j < r)) {
                        for (k in amt downTo 1) {
                            dp[k] += dp[k - 1]
                            if (dp[k] >= MOD) {
                                dp[k] -= MOD
                            }
                        }
                    } else {
                        for (k in 0..amt) {
                            dp[k] *= 2L
                            if (dp[k] >= MOD) {
                                dp[k] -= MOD
                            }
                        }
                    }
                }
            }
            answer += s[r].toLong() * (dp.sum() % MOD)
            answer %= MOD
        }
    }
    println(answer)
}