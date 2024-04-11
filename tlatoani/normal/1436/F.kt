import java.io.BufferedInputStream

const val MOD = 998244353L

fun main() {
    val factors = Array(100001) { mutableListOf<Int>() }
    val mobius = LongArray(100001)
    for (f in 1..100000) {
        for (k in f..100000 step f) {
            factors[k].add(f)
        }
    }
    mobius[1] = 1L
    for (k in 2..100000) {
        mobius[k] = if ((k / factors[k][1]) % factors[k][1] == 0) 0L else -mobius[k / factors[k][1]]
    }
    val jin = FastScanner()
    val sums = LongArray(100001)
    val sums2 = LongArray(100001)
    val amts = LongArray(100001)
    val amtsInt = IntArray(100001)
    for (j in 1..jin.nextInt()) {
        val k = jin.nextInt()
        val kl = k.toLong()
        val amt = jin.nextInt().toLong()
        for (f in factors[k]) {
            sums[f] += amt * kl
            sums[f] %= MOD
            sums2[f] += (amt * ((kl * kl) % MOD))
            sums2[f] %= MOD
            amts[f] += amt
            amts[f] %= MOD
            amtsInt[f] += amt.toInt()
            amtsInt[f] %= MOD_TOTIENT
        }
    }
    var answer = 0L
    for (f in 1..100000) {
        var here = 0L
        if (true) {
            val pairwise = ((sums[f] * sums[f]) - sums2[f]) % MOD
            val n = amtsInt[f] - 2
            val nl = amts[f] - 2L
            val choices = ((2L pow n) + ((2L pow (n - 1)) * nl)) % MOD
            here += pairwise * choices
            answer += mobius[f] * pairwise * choices
            answer %= MOD
        }
        if (true) {
            val pairwise = sums2[f]
            val n = amtsInt[f] - 1
            val nl = amts[f] - 1L
            val choices = ((2L pow (n - 1)) * nl) % MOD
            here += pairwise * choices
            answer += mobius[f] * pairwise * choices
            answer %= MOD
        }
    }
    answer += MOD
    answer %= MOD
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

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
}