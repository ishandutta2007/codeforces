import java.util.*

val MOD = 998244353L

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val k = jin.nextInt()
    val amts = LongArray(n + 1) {
        if (it == 0) {
            0L
        } else {
            val dp = LongArray(n + 1)
            dp[0] = 1L
            var sum = 1L
            for (j in 1..n) {
                dp[j] = sum
                sum += dp[j]
                if (j >= it) {
                    sum -= dp[j - it]
                }
                sum %= MOD
            }
            dp[n]
        }
    }
    for (j in n downTo 1) {
        amts[j] -= amts[j - 1]
    }
    var answer = 0L
    for (a in 1..n) {
        for (b in 1..n) {
            if (a * b < k) {
                answer += amts[a] * amts[b]
                answer %= MOD
            }
        }
    }
    answer *= 2
    println(((answer % MOD) + MOD) % MOD)
}