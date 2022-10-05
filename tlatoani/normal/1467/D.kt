import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 1000000007L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k, q) = jin.readLine().split(" ").map { it.toInt() }
    val dp = Array(k + 1) { LongArray(n + 2) }
    dp[0].fill(1L)
    dp[0][0] = 0L
    dp[0][n + 1] = 0L
    for (s in 1..k) {
        for (j in 1..n) {
            dp[s][j] = (dp[s - 1][j - 1] + dp[s - 1][j + 1]) % MOD
        }
    }
    val overall = LongArray(n + 2)
    for (s in 0..k) {
        for (j in 1..n) {
            overall[j] += dp[s][j] * dp[k - s][j]
            overall[j] %= MOD
        }
    }
    var answer = 0L
    val coef = (listOf(0L) + jin.readLine().split(" ").map { it.toLong() }).toLongArray()
    for (j in 1..n) {
        answer += coef[j] * overall[j]
        answer %= MOD
    }
    val out = StringBuilder()
    for (j in 1..q) {
        val (j, x) = jin.readLine().split(" ").map { it.toInt() }
        answer -= coef[j] * overall[j]
        coef[j] = x.toLong()
        answer += coef[j] * overall[j]
        answer = ((answer % MOD) + MOD) % MOD
        out.appendln(answer)
    }
    print(out)
}