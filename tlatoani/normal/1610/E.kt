import java.io.BufferedInputStream
import java.util.*
import kotlin.math.max

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    repeat(jin.nextInt()) {
        val n = jin.nextInt()
        val ay = IntArray(n) { jin.nextInt() }
        val treeSet = TreeSet<Int>()
        treeSet.addAll(ay.toList())
        var answer = 0
        var last = 0
        var freq = 0
        for (j in 0 until n) {
            if (ay[j] == last) {
                freq++
            } else {
                last = ay[j]
                freq = 1
            }
            var curr = ay[j]
            var amt = freq
            while (true) {
                val next = treeSet.ceiling(max(ay[j] + 1, (2 * curr) - ay[j]))
                if (next == null) {
                    break
                }
                amt++
                curr = next
            }
            answer = max(answer, amt)
        }
        out.appendln(n - answer)
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