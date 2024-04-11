const val MOD = 1000000007L
const val LIMIT = 500000

fun main() {
    val factorial = LongArray(LIMIT + 1)
    factorial[0] = 1L
    for (j in 1..LIMIT) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val factInv = LongArray(LIMIT + 1) { factorial[it] pow -1 }
    fun choose(a: Int, b: Int) = if (a < 0 || b < 0 || b > a) 0L else (factorial[a] * ((factInv[b] * factInv[a - b]) % MOD)) % MOD
    val (a, b, k, t) = readLine()!!.split(" ").map { it.toInt() }
    var answer = 0L
    for (lambda in 0..2 * t) {
        answer += (if (lambda % 2 == 0) 1L else -1L) * choose(2 * t, lambda) * (
                choose((4 * t * k) - (((2 * k) + 1) * lambda) + (2 * t), 2 * t) - choose((2 * t * k) + b - a - (((2 * k) + 1) * lambda) + (2 * t), 2 * t))
        answer %= MOD
    }
    answer += MOD
    answer %= MOD
    println(answer)
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