import java.io.BufferedInputStream
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    cases@for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val piles = LongArray(n + 1) { if (it == 0) 0L else jin.nextInt().toLong() }
        val oddSegtree = LazySegmentTree(1, n)
        val evenSegtree = LazySegmentTree(1, n)
        fun update(j: Int, delta: Long) {
            var signedDelta = if (j % 2 == 0) delta else -delta
            evenSegtree.update(j, n, signedDelta)
            oddSegtree.update(j, n, -signedDelta)
        }
        fun works() = evenSegtree[1, n] >= 0L && oddSegtree[1, n] >= 0L && (if (n % 2 == 0) evenSegtree[n, n] else oddSegtree[n, n]) == 0L
        for (j in 1..n) {
            update(j, piles[j])
            if (j % 2 == 0) {
                oddSegtree.update(j, j, 1000000000000000L)
            } else {
                evenSegtree.update(j, j, 1000000000000000L)
            }
        }
        if (works()) {
            out.appendln("YES")
            continue@cases
        }
        for (j in 2..n) {
            update(j - 1, piles[j] - piles[j - 1])
            update(j, piles[j - 1] - piles[j])
            if (works()) {
                out.appendln("YES")
                continue@cases
            }
            update(j - 1, piles[j - 1] - piles[j])
            update(j, piles[j] - piles[j - 1])
        }
        out.appendln("NO")
    }
    print(out)
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
            value[node] = lazy[node] + min(
                    update(from, to, segFrom, mid, 2 * node, delta),
                    update(from, to, mid + 1, segTo, (2 * node) + 1, delta)
            )
        }
        return value[node]
    }

    operator fun get(from: Int, to: Int) = query(from, to, treeFrom, treeTo, 1)

    fun query(from: Int, to: Int, segFrom: Int, segTo: Int, node: Int): Long {
        if (from > segTo || to < segFrom) {
            return Long.MAX_VALUE
        } else if (from <= segFrom && to >= segTo) {
            return value[node]
        } else {
            val mid = (segFrom + segTo) / 2
            return lazy[node] + min(
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