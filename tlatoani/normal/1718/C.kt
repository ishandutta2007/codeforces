import java.io.BufferedInputStream
import java.util.*
import kotlin.math.max

fun main() {
    val primes = mutableListOf<Int>()
    for (p in 2..450) {
        if (!primes.any { p % it == 0 }) {
            primes.add(p)
        }
    }
    val jin = FastScanner()
    val out = StringBuilder()
    repeat(jin.nextInt()) {
        val n = jin.nextInt()
        val q = jin.nextInt()
        val primeFactors = mutableListOf<Int>()
        var tempN = n
        for (p in primes) {
            if (tempN % p == 0) {
                primeFactors.add(p)
                while (tempN % p == 0) {
                    tempN /= p
                }
            }
        }
        if (tempN != 1) {
            primeFactors.add(tempN)
        }
        val xs = LongArray(n) { jin.nextInt().toLong() }
        val treeSets = Array(primeFactors.size) { PriorityQueue<Pair<Int, Long>>(compareBy { -it.second }) }
        val sums = primeFactors.map { p -> LongArray(n / p) }
        for ((j, p) in primeFactors.withIndex()) {
            for (k in 0 until n) {
                sums[j][k % (n / p)] += xs[k]
            }
            for ((k, x) in sums[j].withIndex()) {
                treeSets[j].add(Pair(k, x))
            }
        }
        fun answer() {
            var answer = 0L
            for ((j, p) in primeFactors.withIndex()) {
                while (true) {
                    val (k, x) = treeSets[j].peek()
                    if (x == sums[j][k]) {
                        answer = max(answer, (n / p).toLong() * x)
                        break
                    } else {
                        treeSets[j].remove()
                    }
                }
            }
            out.appendln(answer)
        }
        answer()
        repeat(q) {
            val k = jin.nextInt() - 1
            val x = jin.nextInt().toLong()
            val prev = xs[k]
            xs[k] = x
            for ((j, p) in primeFactors.withIndex()) {
                val kp = k % (n / p)
                sums[j][kp] -= prev
                sums[j][kp] += x
                treeSets[j].add(Pair(kp, sums[j][kp]))
            }
            answer()
        }
    }
    print(out)
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