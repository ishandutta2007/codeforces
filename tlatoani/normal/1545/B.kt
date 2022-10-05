import java.util.*

const val MOD = 998244353L

fun main() {
    val factorial = LongArray(100001)
    factorial[0] = 1L
    for (k in 1..100000) {
        factorial[k] = (k.toLong() * factorial[k - 1]) % MOD
    }
    val invFactorial = LongArray(100001)
    invFactorial[100000] = factorial[100000] pow -1
    for (k in 99999 downTo 0) {
        invFactorial[k] = ((k + 1).toLong() * invFactorial[k + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (b in 0..a) (factorial[a] * ((invFactorial[b] * invFactorial[a - b]) % MOD)) % MOD else 0L
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        val stack = ArrayDeque<Char>()
        var amtPairs = 0
        for (bit in s) {
            if (bit == '1' && stack.isNotEmpty() && stack.peek() == '1') {
                stack.pop()
                amtPairs++
            } else {
                stack.push(bit)
            }
        }
        var zeros = s.count { it == '0' }
        println(choose(amtPairs + zeros, amtPairs))
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