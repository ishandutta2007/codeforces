import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val degree = IntArray(n + 1)
    for (i in 1..2 * (n - 1)) {
        degree[jin.nextInt()]++
    }
    val factorial = Array(n) { i -> Mint(i) }
    factorial[0] = M1
    for (i in 1 until n) {
        factorial[i] *= factorial[i - 1]
    }
    var answer = Mint(n)
    for (d in degree) {
        answer *= factorial[d]
    }
    println(answer)
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)


val MOD: Long = 998244353
val MOD_TOTIENT = (MOD - 1).toInt()

class Mint {
    val num: Long

    constructor(num: Long) {
        this.num = num % MOD
    }

    constructor(num: Int) {
        this.num = num % MOD
    }

    operator fun plus(k: Mint) = Mint(num + k.num)
    operator fun minus(k: Mint) = Mint(num + MOD - k.num)
    operator fun times(k: Mint) = Mint(num * k.num)
    operator fun div(k: Mint) = this * (k pow -1)

    infix fun pow(power: Int): Mint {
        var e = power
        e %= MOD_TOTIENT
        if (e < 0) {
            e += MOD_TOTIENT
        }
        var b = this
        var res = M1
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
    override fun equals(other: Any?) = other is Mint && num == other.num
}