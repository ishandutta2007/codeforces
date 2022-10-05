import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val s = jin.readLine()
    val t = jin.readLine()
    var dp = LongArray(t.length + 1)
    for (j in 0 until t.length) {
        if (t[j] == s[0]) {
            dp[j] = 2L
        }
    }
    dp[t.length] = 2L
    var dpAlt = LongArray(t.length + 1)
    var answer = 0L
    if (t.length == 1) {
        answer += dp[0]
    }
    for (j in 1 until s.length) {
        dpAlt.fill(0L)
        for (k in 0 until t.length) {
            if (t[k] == s[j]) {
                if (k >= j) {
                    dpAlt[k - j] += dp[k - j]
                    dpAlt[k - j] %= MOD
                }
                dpAlt[k] += dp[k + 1]
                dpAlt[k] %= MOD
            }
        }
        for (k in max(t.length - j, 0)..t.length) {
            dpAlt[k] += dp[k]
            dpAlt[k] %= MOD
        }
        dpAlt[t.length] += dp[t.length]
        dpAlt[t.length] %= MOD
        val temp = dp
        dp = dpAlt
        dpAlt = temp
        if (j + 1 >= t.length) {
            answer += dp[0]
            answer %= MOD
        }
    }
    println(answer)
}