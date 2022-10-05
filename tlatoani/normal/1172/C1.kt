import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(jin.readLine())
    val likes = BooleanArray(n) { tokenizer.nextToken()[0] == '1' }
    tokenizer = StringTokenizer(jin.readLine())
    val w = LongArray(n) { tokenizer.nextToken().toLong() }
    val dp = Array(m + 1) { LongArray(m + 1) }
    dp[0][0] = 1L
    var alpha = 0L
    var beta = 0L
    for (j in 0 until n) {
        if (likes[j]) {
            alpha += w[j]
        } else {
            beta += w[j]
        }
    }
    val gamma = alpha + beta
    val inverses = LongArray((2 * m) + 1) { (gamma + (it - m).toLong()) pow -1 }
    for (j in 1..m) {
        for (a in 0..j) {
            if (a > 0) {
                dp[a][j - a] += ((dp[a - 1][j - a] * (alpha + (a - 1).toLong())) % MOD) * inverses[a - 1 - (j - a) + m]
            }
            if (a < j) {
                dp[a][j - a] += ((dp[a][j - a - 1] * (beta - (j - 1 - a).toLong())) % MOD) * inverses[a - (j - a - 1) + m]
            }
            dp[a][j - a] %= MOD
        }
    }
    var expectedA = 0L
    var expectedB = 0L
    for (a in 0..m) {
        expectedA += a.toLong() * dp[a][m - a]
        expectedA %= MOD
        expectedB -= (m - a).toLong() * dp[a][m - a]
        expectedB %= MOD
    }
    expectedA *= alpha pow -1
    expectedA++
    expectedA %= MOD
    expectedB *= beta pow -1
    expectedB++
    expectedB %= MOD
    val joiner = StringJoiner("\n")
    for (j in 0 until n) {
        val res = w[j] * (if (likes[j]) expectedA else expectedB)
        joiner.add((((res % MOD) + MOD) % MOD).toString())
    }
    println(joiner)
}

val MOD_TOTIENT = (MOD - 1).toInt()

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