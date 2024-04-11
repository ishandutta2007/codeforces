import java.util.*
import kotlin.math.max

const val MOD = 998244353L

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    var answer = 0L
    val dx = Array(m) { Array(n) { 0 } }
    for (j in 0 until n) {
        val tokenizer = StringTokenizer(readLine()!!)
        for (j2 in 0 until m) {
            dx[j2][j] = tokenizer.nextToken().toInt() - 1
        }
    }
    for (ds in dx) {
        ds.sort()
        var here = 1L
        for ((j, d) in ds.withIndex()) {
            here *= max(0, d - j)
            here %= MOD
        }
        answer += here
    }
    answer %= MOD
    for (k in 1..n) {
        answer *= k.toLong() pow -1
        answer %= MOD
    }
    answer = (m.toLong() - answer + MOD) % MOD
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