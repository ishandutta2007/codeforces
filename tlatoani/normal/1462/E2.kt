import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 1000000007L

fun main() {
    val factorial = LongArray(200001)
    factorial[0] = 1L
    for (j in 1..200000) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val factInv = LongArray(200001)
    factInv[200000] = factorial[200000] pow -1
    for (j in 199999 downTo 0) {
        factInv[j] = ((j + 1).toLong() * factInv[j + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (a < 0 || b < 0 || a < b) 0L else (factorial[a] * ((factInv[b] * factInv[a - b]) % MOD)) % MOD
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m, k) = jin.readLine().split(" ").map { it.toInt() }
        val ay = jin.readLine().split(" ").map { it.toInt() }.sorted()
        var answer = 0L
        var j2 = 0
        for (j1 in 0 until n) {
            while (j2 < n && ay[j2] - ay[j1] <= k) {
                j2++
            }
            answer += choose(j2 - j1 - 1, m - 1)
            answer %= MOD
        }
        out.appendln(answer)
    }
    print(out)
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