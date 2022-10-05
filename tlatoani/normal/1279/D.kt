import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val amts = LongArray(1000001)
    val probs = LongArray(1000001)
    for (j in 1..n) {
        val tokenizer = StringTokenizer(jin.readLine())
        val k = tokenizer.nextToken().toInt()
        val denom = (mint(k) pow -1).num
        for (l in 1..k) {
            val a = tokenizer.nextToken().toInt()
            amts[a]++
            probs[a] += denom
            probs[a] %= MOD
        }
    }
    var answer = 0L
    for (a in 1..1000000) {
        answer += probs[a] * amts[a]
        answer %= MOD
    }
    answer *= (mint(n) pow -2).num
    answer %= MOD
    println(answer)
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)

val MOD: Long = 998244353
val MOD_TOTIENT = (MOD - 1).toInt()

fun mint(num: Long) = Mint(num % MOD)
fun mint(num: Int) = Mint(num % MOD)

inline class Mint(val num: Long) {

    operator fun plus(k: Mint) = mint(num + k.num)
    operator fun minus(k: Mint) = mint(num + MOD - k.num)
    operator fun times(k: Mint) = mint(num * k.num)
    operator fun div(k: Mint) = this * (k pow -1)

    operator fun unaryMinus() = mint(MOD - num)
    operator fun inc() = this + M1
    operator fun dec() = this - M1

    infix fun pow(power: Int): Mint {
        var e = power
        e %= MOD_TOTIENT
        if (e < 0) {
            e += MOD_TOTIENT
        }
        if (e == 0 && num == 0L) {
            return this
        }
        var b = this
        var res = Mint(1)
        while (e > 0) {
            if (e and 1 != 0) {
                res *= b
            }
            b *= b
            e = e shr 1
        }
        return res
    }

    override fun toString(): String = num.toString()
}