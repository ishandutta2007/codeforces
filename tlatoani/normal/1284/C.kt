import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    MOD = jin.nextLong()
    val factorial = Array(n + 1) { mint(it) }
    factorial[0] = M1
    for (j in 1..n) {
        factorial[j] *= factorial[j - 1]
    }
    var answer = M0
    for (l in 1..n) {
        answer += mint(n + 1 - l) * mint(n + 1 - l) * factorial[l] * factorial[n - l]
    }
    println(answer)
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)

var MOD: Long = 1000000007 // 998244353
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