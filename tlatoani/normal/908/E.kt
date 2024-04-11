import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val m = jin.nextInt()
    val n = jin.nextInt()
    val t = Array(n) { jin.next() }
    val freq = mutableMapOf<Long, Int>()
    for (j in 0 until m) {
        var mask = 0L
        for (k in 0 until n) {
            mask *= 2L
            mask += t[k][j] - '0'
        }
        freq[mask] = (freq[mask] ?: 0) + 1
    }
    val factorial = LongArray(m + 1) { it.toLong() }
    factorial[0] = 1L
    for (j in 1..m) {
        factorial[j] *= factorial[j - 1]
        factorial[j] %= MOD
    }
    fun choose(a: Int, b: Int) = ((factorial[a]) * ((factorial[b] * factorial[a - b]) pow -1)) % MOD
    val bell = LongArray(m + 1)
    bell[0] = 1L
    for (j in 1..m) {
        for (k in 0 until j) {
            bell[j] += choose(j - 1, k) * bell[k]
            bell[j] %= MOD
        }
        //println("bell[$j] = ${bell[j]}")
    }
    var answer = 1L
    for (f in freq.values) {
        answer *= bell[f]
        answer %= MOD
    }
    println(answer)
}

val MOD: Long = 1000000007
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