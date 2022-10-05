const val MOD = 1000000007L

fun main() {
    val n = readLine()!!.toInt()
    val inv = LongArray(n + 1) { it.toLong() pow -1 }
    val factorial = LongArray(n + 1)
    val factInv = LongArray(n + 1)
    factorial[0] = 1L
    factInv[0] = 1L
    for (j in 1..n) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
        factInv[j] = (inv[j] * factInv[j - 1]) % MOD
    }
    fun permute(a: Int, b: Int) = (factorial[a] * factInv[b]) % MOD
    fun arrange(a: Int, b: Int): Long {
        val here = n / a
        val above = here / b
        return ((here - above).toLong() * permute(n - above - 1, n - here)) % MOD
    }
    fun arrangeInv(a: Int, b: Int): Long {
        val here = n / a
        val above = here / b
        return (inv[here - above] * permute(n - here, n - above - 1)) % MOD
    }
    var lg = 0
    while (1 shl lg <= n) {
        lg++
    }
    lg--
    var curr = 1L
    for (e in 0..lg) {
        curr *= arrange(1 shl e, 2)
        curr %= MOD
    }
    var answer = curr
    if (n >= 3 * (1 shl (lg - 1))) {
        for (e in lg downTo 1) {
            curr *= arrangeInv(1 shl e, 3)
            curr %= MOD
            curr *= arrange(3 * (1 shl (e - 1)), 2)
            curr %= MOD
            curr *= arrangeInv(1 shl (e - 1), 2)
            curr %= MOD
            curr *= arrange(1 shl (e - 1), 3)
            curr %= MOD
            answer += curr
        }
        answer %= MOD
    }
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