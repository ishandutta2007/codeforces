import java.io.BufferedInputStream
import kotlin.math.max

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    repeat(jin.nextInt()) {
        val n = jin.nextInt()
        val xs = List(n) { jin.nextInt().toLong() }.sorted()
        val sum = xs.sum()
        if (sum + ((n - 2).toLong() * xs[0]) > 0L || sum + ((n - 2).toLong() * xs.last()) < 0L) {
            out.appendln("INF")
        } else if (n == 2) {
            out.appendln(xs[0] * xs.last())
        } else {
            var constant = (sum - xs[0]) * xs[0]
            var coefficient = sum + ((n - 2L).toLong() * xs[0])
            var answer = Long.MIN_VALUE
            for (j in 1..n - 2) {
                constant += xs[j] * (xs.last() - xs[0])
                coefficient += xs.last() - xs[0]
                answer = max(answer, constant + (coefficient * -xs[j]))
            }
            out.appendln(answer)
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