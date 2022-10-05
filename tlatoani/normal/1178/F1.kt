import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val strip = IntArray(n + 1) { jin.nextInt() }
    val dp = Array(n + 2) { Array(n + 2) { M1 } }
    for (l in n downTo 1) {
        var leastColor = n + 1
        var leastColorIx = -1
        for (r in l..n) {
            if (strip[r] < leastColor) {
                leastColor = strip[r]
                leastColorIx = r
            }
            var leftSum = M0
            for (a in l..leastColorIx) {
                leftSum += dp[l][a - 1] * dp[a][leastColorIx - 1]
            }
            var rightSum = M0
            for (b in leastColorIx..r) {
                rightSum += dp[leastColorIx + 1][b] * dp[b + 1][r]
            }
            dp[l][r] = leftSum * rightSum
        }
    }
    println(dp[1][n])
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