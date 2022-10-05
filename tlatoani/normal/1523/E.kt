import kotlin.math.min

const val MOD = 1000000007L

fun main() {
    val factorial = LongArray(100001)
    factorial[0] = 1L
    for (j in 1..100000) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val invFactorial = LongArray(100001)
    invFactorial[100000] = factorial[100000] pow -1
    for (j in 99999 downTo 0) {
        invFactorial[j] = ((j + 1).toLong() * invFactorial[j + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (b in 0..a) (factorial[a] * ((invFactorial[b] * invFactorial[a - b]) % MOD)) % MOD else 0L
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        if (k == 1) {
            println(n)
        } else {
            var answer = 0L
            for (j in 2..min(n, (n / (k - 1)) + 3)) {
                val x = (((((j - 1).toLong() * (choose(n - ((j - 2) * (k - 1)), j) - choose(n - ((j - 1) * (k - 1)), j))) % MOD)))
                answer += j.toLong() * (((((j - 1).toLong() * (choose(n - ((j - 2) * (k - 1)), j) - choose(n - ((j - 1) * (k - 1)), j))) % MOD) * ((2L * factorial[j - 1] * factorial[n - j]) % MOD)) % MOD)
                answer %= MOD
            }
            for (j in 3..min(n, (n / (k - 1)) + 3)) {
                var y = (choose(n - ((j - 3) * (k - 1)), j) - (2L * choose(n - ((j - 2) * (k - 1)), j)) + choose(n - ((j - 1) * (k - 1)), j)) % MOD
                for (s in 1..k - 2) {
                    y -= s.toLong() * choose(n - ((j - 3) * (k - 1)) - s - 1, j - 2)
                    y %= MOD
                }
                answer += j.toLong() * (((((j - 2).toLong() * y) % MOD) * ((factorial[j - 1] * factorial[n - j]) % MOD)) % MOD)
                answer %= MOD
            }
            answer *= invFactorial[n]
            answer %= MOD
            answer += MOD
            answer %= MOD
            println(answer)
        }
    }
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