import java.io.BufferedReader
import java.io.InputStreamReader

val MOD = 1000000007L

fun main() {
    val lastPrime = IntArray(1000001) { 1 }
    for (p in 2..999999) {
        if (lastPrime[p] == 1) {
            var x = p
            while (x <= 1000000) {
                lastPrime[x] = p
                x += p
            }
        }
    }
    val factorial = LongArray(1000021) { it.toLong() }
    factorial[0] = 1L
    for (j in 1..1000020) {
        factorial[j] *= factorial[j - 1]
        factorial[j] %= MOD
    }
    fun choose(n: Int, k: Int) = (factorial[n] * ((factorial[k] * factorial[n - k]) pow -1)) % MOD
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (j in 1..jin.readLine().toInt()) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        var x = line.substring(0, six).toInt()
        val y = line.substring(six + 1).toInt()
        var answer = 1L
        while (x != 1) {
            var p = lastPrime[x]
            var e = 0
            while (x % p == 0) {
                x /= p
                e++
            }
            answer *= choose(y - 1 + e, e)
            answer %= MOD
        }
        answer *= 2L pow (y - 1)
        answer %= MOD
        out.appendln(answer)
    }
    print(out)
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