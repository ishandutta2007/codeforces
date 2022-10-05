import java.io.BufferedInputStream
import kotlin.math.min
import kotlin.random.Random

fun main() {
    val random = Random(System.currentTimeMillis())
    val jin = FastScanner()
    val n = jin.nextInt()
    val s = jin.nextInt()
    val d = jin.nextInt()
    val hashFunction = LongArray(n + 1) { random.nextLong() }
    val hashes = LongArray(s) {
        var res = 0L
        for (j in 1..jin.nextInt()) {
            res = res xor hashFunction[jin.nextInt()]
        }
        res
    }
    val left = mutableListOf<Pair<Int, Long>>()
    for (mask in 0 until (1 shl (s / 2))) {
        var hash = 0L
        for (j in 0 until s / 2) {
            if (mask and (1 shl j) != 0) {
                hash = hash xor hashes[j]
            }
        }
        left.add(Pair(Integer.bitCount(mask), hash))
    }
    val right = mutableMapOf<Long, Int>()
    for (mask in 0 until (1 shl ((s + 1) / 2))) {
        var hash = 0L
        for (j in 0 until (s + 1) / 2) {
            if (mask and (1 shl j) != 0) {
                hash = hash xor hashes[(s / 2) + j]
            }
        }
        val amt = Integer.bitCount(mask)
        right.compute(hash) { _, v -> min(v ?: 115, amt) }
    }
    val out = StringBuilder()
    for (j in 1..d) {
        var hash = 0L
        for (j2 in 1..jin.nextInt()) {
            hash = hash xor hashFunction[jin.nextInt()]
        }
        var res = 115
        for (l in left) {
            res = min(res, l.first + (right[hash xor l.second] ?: 115))
        }
        if (res == 115) {
            res = -1
        }
        out.appendln(res)
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