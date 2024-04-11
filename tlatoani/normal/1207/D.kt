import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val pairs = mutableMapOf<Pair<Int, Int>, Int>()
    val first = Array(n) { 0 }
    val second = Array(n) { 0 }
    for (i in 0 until n) {
        first[i] = jin.nextInt()
        second[i] = jin.nextInt()
        if (pairs.contains(Pair(first[i], second[i]))) {
            pairs[Pair(first[i], second[i])] = pairs[Pair(first[i], second[i])]!! + 1
        } else {
            pairs[Pair(first[i], second[i])] = 1
        }
    }
    first.sort()
    second.sort()
    var both = M1
    var bothCurr = M0
    var ein = M1
    var firstCurr = M0
    var zwei = M1
    var secondCurr = M0
    var total = M1
    for (i in 0 until n) {
        if (pairs.contains(Pair(first[i], second[i])) && pairs[Pair(first[i], second[i])]!! > 0) {
            pairs[Pair(first[i], second[i])] = pairs[Pair(first[i], second[i])]!! - 1
        } else {
            both = M0
        }
        if (i > 0 && first[i] == first[i - 1] && second[i] == second[i - 1]) {
            bothCurr++
        } else {
            bothCurr = M1
        }
        if (i > 0 && first[i] == first[i - 1]) {
            firstCurr++
        } else {
            firstCurr = M1
        }
        if (i > 0 && second[i] == second[i - 1]) {
            secondCurr++
        } else {
            secondCurr = M1
        }
        both *= bothCurr
        ein *= firstCurr
        zwei *= secondCurr
        total *= mint(i + 1)
    }
    println(total - zwei - ein + both)
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