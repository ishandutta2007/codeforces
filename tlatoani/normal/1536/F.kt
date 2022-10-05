const val MOD = 1000000007L

fun main() {
    val n = readLine()!!.toInt()
    val factorial = LongArray(n + 1)
    factorial[0] = 1L
    for (j in 1..n) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val invFactorial = LongArray(n + 1)
    invFactorial[n] = factorial[n] pow -1
    for (j in n - 1 downTo 0) {
        invFactorial[j] = ((j + 1).toLong() * invFactorial[j + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (b in 0..a) ((factorial[a] * ((invFactorial[b] * invFactorial[a - b]) % MOD)) % MOD) else 0L
    var answer = 0L
    for (k in 0..n step 2) {
        answer += factorial[k] * (choose(k, n - k) + choose(k - 1, n - k - 1))
        answer %= MOD
    }
    answer *= 2L
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