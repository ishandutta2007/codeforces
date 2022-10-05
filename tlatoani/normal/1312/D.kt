import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    if (n == 2) {
        println(0)
        return
    }
    val pow2 = LongArray(200001)
    val factorial = LongArray(200001)
    pow2[0] = 1L
    factorial[0] = 1L
    for (j in 1..200000) {
        pow2[j] = (2L * pow2[j - 1]) % MOD
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (b < 0 || b > a) 0L else (factorial[a] * ((factorial[b] * factorial[a - b]) pow -1)) % MOD
    var answer = 0L
    for (k in 1..m) {
        answer += (k - 1).toLong() * ((choose(k - 2, n - 3) * pow2[n - 3]) % MOD)
        //println("k = $k, answer = $answer")
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