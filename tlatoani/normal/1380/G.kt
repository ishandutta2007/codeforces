import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val treasures = jin.readLine().split(" ").map { it.toLong() }.sorted()
    val sums = LongArray(n + 1)
    for (j in 1..n) {
        sums[j] = (sums[j - 1] + treasures[j - 1]) % MOD
    }
    val nInv = n.toLong() pow -1
    val joiner = StringJoiner(" ")
    for (k in 1..n) {
        var j = n - k
        var res = 0L
        while (j > 0) {
            res += sums[j]
            j -= k
        }
        res %= MOD
        res *= nInv
        res %= MOD
        joiner.add(res.toString())
    }
    println(joiner)
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