const val MOD = 1000000007L

fun main() {
    val factorial = LongArray(400001)
    factorial[0] = 1L
    for (k in 1..400000) {
        factorial[k] = (k.toLong() * factorial[k - 1]) % MOD
    }
    val invFact = LongArray(400001)
    invFact[400000] = factorial[400000] pow -1
    for (k in 399999 downTo 0) {
        invFact[k] = ((k + 1).toLong() * invFact[k + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (b <= a) (factorial[a] * ((invFact[b] * invFact[a - b]) % MOD)) % MOD else 0L
    val n = readLine()!!.toInt()
    val xs = readLine()!!.split(" ").map { it.toInt() }
    var answer = 0L
    for (y in 0..n) {
        answer += choose(y + xs[y], y + 1)
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

/*

11
12 11 8 8 6 6 6 5 3 2 1 0


 */