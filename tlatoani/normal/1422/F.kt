import java.io.BufferedInputStream
import kotlin.math.max
import kotlin.math.min

const val MOD = 1000000007L

val PRIMES = listOf(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53)

fun main() {
    val primeFactors = IntArray(200001) { 1 }
    for (p in 2..200000) {
        if (primeFactors[p] == 1) {
            for (k in p..200000 step p) {
                primeFactors[k] = p
            }
        }
    }
    val jin = FastScanner()
    val n = jin.nextInt()
    val ay = Array(n + 1) { if (it == 0) 0 else jin.nextInt() }
    val smalls = PRIMES.map { Pair(it, MaxSegmentTree(1, n)) }
    val last = IntArray(200001)
    val last2 = IntArray(200001)
    val things = Array(n + 1) { mutableListOf<Thing>() }
    val things2 = Array(n + 1) { mutableListOf<Thing>() }
    for (j in 1..n) {
        var k = ay[j]
        for ((p, segTree) in smalls) {
            var power = 1
            while (k % p == 0) {
                k /= p
                power *= p
            }
            segTree[j] = power
        }
        while (k != 1) {
            val p = primeFactors[k]
            k /= p
            things[j].add(Thing(last[p], p.toLong()))
            last[p] = j
            if (k % p == 0) {
                k /= p
                things2[j].add(Thing(last2[p], p.toLong()))
                last2[p] = j
            }
        }
    }
    val thingSegTree = ThingSegmentTree(n, things)
    val thingSegTree2 = ThingSegmentTree(n, things2)
    val out = StringBuilder()
    var res = 0L
    for (j in 1..jin.nextInt()) {
        val x = jin.nextInt()
        val y = jin.nextInt()
        val a = ((res.toInt() + x) % n) + 1
        val b = ((res.toInt() + y) % n) + 1
        val from = min(a, b)
        val to = max(a, b)
        res = 1L
        for ((_, segTree) in smalls) {
            res *= segTree[from, to].toLong()
            res %= MOD
        }
        res *= thingSegTree[from, to]
        res %= MOD
        res *= thingSegTree2[from, to]
        res %= MOD
        out.appendln(res)
    }
    print(out)
}

data class Thing(val last: Int, val p: Long)

class ThingSegmentTree(val n: Int, val things: Array<MutableList<Thing>>) {
    val segments = Array(300000) { mutableListOf<Pair<Int, Long>>() }

    init {
        init(1, 1, n)
    }

    fun init(node: Int, segFrom: Int, segTo: Int): List<Thing> {
        val here: MutableList<Thing>
        if (segFrom == segTo) {
            here = things[segFrom]
            here.sortBy { it.last }
        } else {
            val mid = (segFrom + segTo) / 2
            val left = init(2 * node, segFrom, mid)
            val right = init((2 * node) + 1, mid + 1, segTo)
            here = ArrayList(left.size + right.size)
            var j = 0
            var k = 0
            while (j < left.size || k < right.size) {
                if (j < left.size && (k == right.size || left[j].last < right[k].last)) {
                    here.add(left[j])
                    j++
                } else {
                    here.add(right[k])
                    k++
                }
            }
        }
        segments[node].add(Pair(0, 1L))
        for (thing in here) {
            segments[node].add(Pair(thing.last, (segments[node].last().second * thing.p) % MOD))
        }
        return here
    }

    operator fun get(from: Int, to: Int) = query(from, to, 1, 1, n)

    fun query(from: Int, to: Int, node: Int, segFrom: Int, segTo: Int): Long {
        if (segTo < from || to < segFrom) {
            return 1L
        } else if (from <= segFrom && segTo <= to) {
            var upper = segments[node].lastIndex
            var lower = 0
            while (upper > lower) {
                val mid = (upper + lower + 1) / 2
                if (segments[node][mid].first < from) {
                    lower = mid
                } else {
                    upper = mid - 1
                }
            }
            return segments[node][upper].second
        } else {
            val mid = (segFrom + segTo) / 2
            return (query(from, to, 2 * node, segFrom, mid) * query(from, to, (2 * node) + 1, mid + 1, segTo)) % MOD
        }
    }
}

class MaxSegmentTree(val treeFrom: Int, treeTo: Int) {
    val value: IntArray
    val length: Int

    init {
        var e = 0
        while (1 shl e < treeTo - treeFrom + 1) {
            e++
        }
        value = IntArray(1 shl (e + 1))
        length = 1 shl e
    }

    operator fun set(index: Int, delta: Int) {
        var node = index - treeFrom + length
        value[node] = delta
        node = node shr 1
        while (node > 0) {
            value[node] = max(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromIndex: Int, toIndex: Int): Int {
        if (toIndex < fromIndex) {
            return 0
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Int = 0
        while (from + (from and -from) <= to) {
            res = max(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = max(res, value[(to - (to and -to)) / (to and -to)])
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