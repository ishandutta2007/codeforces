import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val from = IntArray(n) { jin.nextInt() }
    val to = IntArray(n) { jin.nextInt() }
    val lens = Array(n) { i -> mint(to[i] - from[i] + 1) }
    var b = M1
    val adjProbs = Array(n - 1) { i ->
        val rangeLen = mint(maxOf(0, minOf(to[i], to[i + 1]) - maxOf(from[i], from[i + 1]) + 1))
        val res = M1 - (rangeLen / (lens[i] * lens[i + 1]))
        b += res
        res
    }
    var answer = b pow 2
    for (p in adjProbs) {
        answer -= p pow 2
        answer += p
    }
    for (i in 1 until n - 1) {
        val abcLen = mint(maxOf(0, minOf(to[i - 1], to[i], to[i + 1]) - maxOf(from[i - 1], from[i], from[i + 1]) + 1))
        val abLen = mint(maxOf(0, minOf(to[i - 1], to[i]) - maxOf(from[i - 1], from[i]) + 1))
        val bcLen = mint(maxOf(0, minOf(to[i], to[i + 1]) - maxOf(from[i], from[i + 1]) + 1))
        var p = abcLen * (lens[i - 1] - M1) * (lens[i + 1] - M1)
        p += (abLen - abcLen) * (lens[i - 1] - M1) * lens[i + 1]
        p += (bcLen - abcLen) * lens[i - 1] * (lens[i + 1] - M1)
        p += (lens[i] - abLen - bcLen + abcLen) * lens[i - 1] * lens[i + 1]
        p /= lens[i - 1] * lens[i] * lens[i + 1]
        answer -= M2 * adjProbs[i - 1] * adjProbs[i]
        answer += M2 * p
    }
    println(answer)
}

val M0 = Mint(0)
val M1 = Mint(1)
val M2 = Mint(2)

val MOD: Long = 1000000007
val MOD_TOTIENT = (MOD - 1).toInt()

fun mint(num: Long) = Mint(num % MOD)
fun mint(num: Int) = Mint(num % MOD)

inline class Mint(val num: Long) {

    operator fun plus(k: Mint) = mint(num + k.num)
    operator fun minus(k: Mint) = mint(num + MOD - k.num)
    operator fun times(k: Mint) = mint(num * k.num)
    operator fun div(k: Mint) = this * (k pow -1)

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