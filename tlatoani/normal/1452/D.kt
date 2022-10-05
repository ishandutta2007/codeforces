const val MOD = 998244353L

fun main() {
    val n = readLine()!!.toInt()
    val factorial = LongArray((2 * n) + 1)
    factorial[0] = 1L
    for (j in 1..2 * n) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val factInv = LongArray((2 * n) + 1)
    factInv[2 * n] = factorial[2 * n] pow -1
    for (j in (2 * n) - 1 downTo 0) {
        factInv[j] = ((j + 1).toLong() * factInv[j + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (a < 0 || b !in 0..a) 0L else (factorial[a] * ((factInv[b] * factInv[a - b]) % MOD)) % MOD
    var answer = 0L
    for (k in (n % 2)..n step 2) {
        answer += choose(((n - k) / 2) + k - 1, k - 1)
    }
    answer %= MOD
    answer *= 2L pow -n
    answer %= MOD
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