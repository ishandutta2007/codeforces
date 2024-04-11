import java.util.*

fun main() {
    val powersOfTen = Array(20) { M10 }
    powersOfTen[0] = M1
    for (e in 1..19) {
        powersOfTen[e] *= powersOfTen[e - 1]
    }
    val jin = Scanner(System.`in`)
    val n = jin.nextLong()
    val array = Array(n.toInt()) { jin.next().reversed() }
    val amts = Array(11) { M0 }
    for (a in array) {
        amts[a.length]++
    }
    var answer = M0
    for (a in array) {
        for (i in 0 until a.length) {
            val digit = mint(a[i] - '0')
            for (j in 1..i) {
                answer += M2 * amts[j] * powersOfTen[i + j] * digit
            }
            for (j in i + 1..10) {
                answer += M11 * amts[j] * powersOfTen[2 * i] * digit
            }
        }
    }
    println(answer)
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)
val M10 = Mint(10)
val M11 = Mint(11)

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