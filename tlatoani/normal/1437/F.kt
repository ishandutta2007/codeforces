import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val ay = listOf(0) + jin.readLine().split(" ").map { it.toInt() }.sorted()
    if (ay[n] < 2 * ay[n - 1]) {
        println(0)
        return
    }
    val dp = LongArray(n + 1)
    dp[n] = 1L
    for (j in n - 1 downTo 0) {
        var k1 = if (j == 0) 0 else (0..n).first { 2 * ay[it] > ay[j] }
        var k2 = (0..n).first { 2 * ay[j] <= ay[it] }
        for (k in k2..n) {
            dp[j] += dp[k]
            dp[j] %= MOD
        }
        dp[j] *= (n - k1).toLong() pow -1
        dp[j] %= MOD
    }
    var answer = dp[0]
    for (j in 1L..n.toLong()) {
        answer *= j
        answer %= MOD
    }
    println(answer)
}

const val MOD_TOTIENT = MOD.toInt() - 1

infix fun Long.pow(power: Int): Long {
    var e = power
    e %= MOD_TOTIENT
    if (e < 0) {
        e += MOD_TOTIENT
    }
    if (e == 0 && this == 0L) {
        return this
    }
    var b = this % MOD
    var res = 1L
    while (e > 0) {
        if (e and 1 != 0) {
            res *= b
            res %= MOD
        }
        b *= b
        b %= MOD
        e = e shr 1
    }
    return res
}