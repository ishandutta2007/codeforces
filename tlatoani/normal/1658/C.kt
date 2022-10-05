import java.io.BufferedInputStream
import java.util.*

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    repeat(jin.nextInt()) {
        val n = jin.nextInt()
        var powers = List(n) { jin.nextInt() }
        powers = powers.subList(0, 1) + powers.subList(1, n).reversed()
        val maxIndex = powers.indices.find { powers[it] == 1 }
        if (maxIndex == null) {
            out.appendln("nO")
        } else {
            powers = powers.subList(maxIndex + 1, n) + powers.subList(0, maxIndex + 1)
            val left = IntArray(n) { -1 }
            val right = IntArray(n) { -1 }
            val stack = Stack<Int>()
            for (j in 0 until n) {
                while (stack.isNotEmpty() && powers[j] < powers[stack.peek()]) {
                    left[j] = stack.pop()
                }
                if (stack.isNotEmpty()) {
                    right[stack.peek()] = j
                }
                stack.push(j)
            }
            if (n - 1 !in right && (0 until n).all { j -> (left[j] == -1 || powers[left[j]] == powers[j] + 1) && (right[j] == -1 || powers[right[j]] == powers[j]) }) {
                out.appendln("yEs")
            } else {
                out.appendln("nO")
            }
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