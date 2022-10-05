const val MOD = 1000000007L

fun main() {
    readLine()
    val fs = readLine()!!.split(" ").map { it.toInt() }
    val n = fs.sum().toLong()
    val expected = LongArray(100001)
    expected[1] = (((n - 1L) pow 2) * (n pow -1)) % MOD
    for (k in 1..99999) {
        expected[k + 1] = ((2L * expected[k]) - expected[k - 1] - ((n - 1L) * ((n - k.toLong()) pow -1))) % MOD
    }
    val answer = fs.map { expected[it] }.sum() % MOD
    println((answer + MOD) % MOD)
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