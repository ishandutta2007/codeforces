import java.io.BufferedInputStream
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val m = jin.nextInt()
    val segTree = DecimalSegmentTree(n)
    for (j in 1..n) {
        segTree.initSet(j, jin.nextInt())
    }
    segTree.init()
    val out = StringBuilder()
    for (j in 1..m) {
        if (jin.nextInt() == 1) {
            val j = jin.nextInt()
            val x = jin.nextInt()
            segTree[j] = x
        } else {
            val l = jin.nextInt()
            val r = jin.nextInt()
            val res = segTree[l, r]
            out.appendln(if (res == Int.MAX_VALUE) -1 else res)
        }
    }
    print(out)
}

class DecimalSegmentTree(treeTo: Int) {
    val value: Array<IntArray>
    val pos: IntArray
    val length: Int

    init {
        var e = 0
        while (1 shl e < treeTo) {
            e++
        }
        value = Array(9) { IntArray(1 shl (e + 1)) { Int.MAX_VALUE } }
        pos = IntArray(1 shl (e + 1)) { Int.MAX_VALUE }
        length = 1 shl e
    }

    fun initSet(index: Int, delta: Int) {
        var node = index - 1 + length
        var curr = delta
        for (e in 0..8) {
            if (curr % 10 == 0) {
                value[e][node] = Int.MAX_VALUE
            } else {
                value[e][node] = delta
            }
            curr /= 10
        }
    }

    fun init() {
        for (node in length - 1 downTo 1) {
            val left = node shl 1
            val right = (node shl 1) + 1
            pos[node] = min(pos[left], pos[right])
            for (e in 0..8) {
                val a = value[e][left]
                val b = value[e][right]
                value[e][node] = min(a, b)
                if (a != Int.MAX_VALUE && b != Int.MAX_VALUE) {
                    pos[node] = min(pos[node], a + b)
                }
            }
        }
    }

    operator fun set(index: Int, delta: Int) {
        var node = index - 1 + length
        var curr = delta
        for (e in 0..8) {
            if (curr % 10 == 0) {
                value[e][node] = Int.MAX_VALUE
            } else {
                value[e][node] = delta
            }
            curr /= 10
        }
        node = node shr 1
        while (node > 0) {
            val left = node shl 1
            val right = (node shl 1) + 1
            pos[node] = min(pos[left], pos[right])
            for (e in 0..8) {
                val a = value[e][left]
                val b = value[e][right]
                value[e][node] = min(a, b)
                if (a != Int.MAX_VALUE && b != Int.MAX_VALUE) {
                    pos[node] = min(pos[node], a + b)
                }
            }
            node = node shr 1
        }
    }

    val interm = IntArray(9)

    operator fun get(fromIndex: Int, toIndex: Int): Int {
        var from = fromIndex + length - 1
        var to = toIndex + length
        var res = Int.MAX_VALUE
        interm.fill(Int.MAX_VALUE)
        while (from + (from and -from) <= to) {
            val node = from / (from and -from)
            res = min(res, pos[node])
            for (e in 0..8) {
                if (interm[e] != Int.MAX_VALUE && value[e][node] != Int.MAX_VALUE) {
                    res = min(res, interm[e] + value[e][node])
                }
                interm[e] = min(interm[e], value[e][node])
            }
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            val node = (to - (to and -to)) / (to and -to)
            res = min(res, pos[node])
            for (e in 0..8) {
                if (interm[e] != Int.MAX_VALUE && value[e][node] != Int.MAX_VALUE) {
                    res = min(res, interm[e] + value[e][node])
                }
                interm[e] = min(interm[e], value[e][node])
            }
            to -= to and -to
        }
        return res
    }
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