import java.util.*

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)
val MHALF = M2 pow -1

var nu = M0
var kappa = M0
var comb = M1
var combSum = M1

fun right() {
    kappa += M1
    comb *= nu + M1 - kappa
    comb /= kappa
    combSum += comb
}

fun left() {
    combSum -= comb
    comb *= kappa
    comb /= nu + M1 - kappa
    kappa -= M1
}

fun up() {
    val oldComb = comb
    val oldSum = combSum
    left()
    comb += oldComb
    comb *= MHALF
    combSum += oldSum
    combSum *= MHALF
    nu += M1
    kappa += M1
}

fun travel(newNu: Mint, newKappa: Mint) {
    while (nu.num < newNu.num) {
        up()
    }
    while (kappa.num < newKappa.num) {
        right()
    }
    while (kappa.num > newKappa.num) {
        left()
    }
}

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val t = jin.nextLong()
    val times = LongArray(n) { jin.nextLong() }
    var answer = M0
    var minTimeSum: Long = 0
    for (i: Long in 1L..n) {
        minTimeSum += times[i.toInt() - 1]
        if (minTimeSum + i <= t) {
            answer += M1
        } else if (minTimeSum <= t) {
            travel(Mint(i), Mint(t - minTimeSum))
            answer += combSum
        } else {
            break
        }
    }
    println(answer)
}

val MOD: Long = 1000000007
val MOD_TOTIENT = (MOD - 1).toInt()

fun mint(num: Long) = Mint(num % MOD)
fun mint(num: Int) = Mint(num % MOD)

inline class Mint(val num: Long) {

    operator fun plus(k: Mint) = mint(num + k.num)
    operator fun minus(k: Mint) = mint(num + MOD - k.num)
    operator fun times(k: Mint) = mint(num * k.num)
    operator fun div(k: Mint) = this * (k pow -1)

    operator fun unaryMinus() = mint(MOD - num)

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