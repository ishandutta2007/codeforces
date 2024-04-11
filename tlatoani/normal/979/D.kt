import java.io.BufferedInputStream
import kotlin.math.min

const val LIMIT = 30000000

fun main() {
    val factors = Array(100001) { mutableListOf<Int>() }
    for (f in 1..100000) {
        for (k in f..100000 step f) {
            factors[k].add(f)
        }
    }
    val left = IntArray(LIMIT)
    val right = IntArray(LIMIT)
    val min = IntArray(LIMIT) { 115115 }
    val jin = FastScanner()
    val out = StringBuilder()
    var nextNode = 100001
    for (j in 1..jin.nextInt()) {
        if (jin.nextInt() == 1) {
            val k = jin.nextInt()
            for (f in factors[k]) {
                var node = f
                min[node] = min(min[node], k)
                for (e in 16 downTo 0) {
                    if (k and (1 shl e) == 0) {
                        if (left[node] == 0) {
                            left[node] = nextNode
                            nextNode++
                        }
                        node = left[node]
                    } else {
                        if (right[node] == 0) {
                            right[node] = nextNode
                            nextNode++
                        }
                        node = right[node]
                    }
                    min[node] = min(min[node], k)
                }
            }
        } else {
            val x = jin.nextInt()
            val k = jin.nextInt()
            val d = jin.nextInt() - x
            if (x % k == 0 && min[k] <= d) {
                var node = k
                for (e in 16 downTo 0) {
                    node = if (x and (1 shl e) == 0) {
                        if (min[right[node]] <= d) right[node] else left[node]
                    } else {
                        if (min[left[node]] <= d) left[node] else right[node]
                    }
                }
                out.appendln(min[node])
            } else {
                out.appendln(-1)
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