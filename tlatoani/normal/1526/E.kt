const val MOD = 998244353L

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val p = readLine()!!.split(" ").map { it.toInt() }
    val q = IntArray(n + 1)
    for (j in 0 until n) {
        q[p[j]] = j
    }
    q[n] = -1
    var increases = k - 1 - (1 until n).count { j -> q[p[j - 1] + 1] > q[p[j] + 1] }
    val factorial = LongArray(n + increases + 1)
    factorial[0] = 1L
    for (j in 1..n + increases) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val answer = if (increases < 0) 0L else (factorial[n + increases] * ((factorial[n] * factorial[increases]) pow -1)) % MOD
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