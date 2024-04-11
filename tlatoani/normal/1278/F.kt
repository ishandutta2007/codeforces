import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val mInv = mint(jin.nextInt()) pow -1
    val k = jin.nextInt()
    val dp = Array(k + 1) { LongArray(it + 2) }
    dp[0][0] = 1L
    for (x in 1..k) {
        for (y in 1..x) {
            dp[x][y] = ((n - y + 1).toLong() * dp[x - 1][y - 1]) + (y.toLong() * dp[x - 1][y])
            dp[x][y] %= MOD
        }
    }
    var answer = M0
    var power = M1
    for (y in 1..k) {
        power *= mInv
        answer += mint(dp[k][y] + MOD) * power
    }
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