import java.io.BufferedInputStream
import java.util.*
import kotlin.math.max

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val heights = IntArray(n + 1) { if (it == 0) 0 else jin.nextInt() }
    val beauties = LongArray(n + 1) { if (it == 0) 0L else jin.nextInt().toLong() }
    val segTree = LazySegmentTree(0, n)
    val stack = Stack<Int>()
    stack.push(0)
    for (j in 1..n) {
        segTree.update(j - 1, j - 1, beauties[j])
        while (heights[j] <= heights[stack.peek()]) {
            val k = stack.pop()
            segTree.update(stack.peek(), k - 1, beauties[j] - beauties[k])
        }
        stack.push(j)
        segTree.update(j, j, segTree[0, j - 1])
    }
    println(segTree[n, n])
}

class LazySegmentTree(val treeFrom: Int, val treeTo: Int) {
    val value: LongArray
    val lazy: LongArray

    init {
        val length = treeTo - treeFrom + 1
        var e = 0
        while (1 shl e < length) {
            e++
        }
        value = LongArray(1 shl (e + 1))
        lazy = LongArray(1 shl (e + 1))
    }

    fun update(from: Int, to: Int, delta: Long) {
        update(from, to, treeFrom, treeTo, 1, delta)
    }

    fun update(from: Int, to: Int, segFrom: Int, segTo: Int, node: Int, delta: Long): Long {
        if (from > segTo || to < segFrom) {

        } else if (from <= segFrom && to >= segTo) {
            value[node] += delta
            lazy[node] += delta
        } else {
            val mid = (segFrom + segTo) / 2
            value[node] = lazy[node] + max(
                    update(from, to, segFrom, mid, 2 * node, delta),
                    update(from, to, mid + 1, segTo, (2 * node) + 1, delta)
            )
        }
        return value[node]
    }

    operator fun get(from: Int, to: Int) = query(from, to, treeFrom, treeTo, 1)

    fun query(from: Int, to: Int, segFrom: Int, segTo: Int, node: Int): Long {
        if (from > segTo || to < segFrom) {
            return -10000000000000000L
        } else if (from <= segFrom && to >= segTo) {
            return value[node]
        } else {
            val mid = (segFrom + segTo) / 2
            return lazy[node] + max(
                    query(from, to, segFrom, mid, 2 * node),
                    query(from, to, mid + 1, segTo, (2 * node) + 1)
            )
        }
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