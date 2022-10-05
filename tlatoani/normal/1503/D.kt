import java.io.BufferedInputStream
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val initial = BooleanArray(n + 1)
    val order = IntArray(2 * n)
    var maxFirst = 0
    var minLast = 2 * n
    for (j in 1..n) {
        val a = jin.nextInt() - 1
        val b = jin.nextInt() - 1
        if (a < b) {
            initial[j] = true
        }
        order[a] = j
        order[b] = j
        maxFirst = max(maxFirst, min(a, b))
        minLast = min(minLast, max(a, b))
    }
    if (maxFirst > minLast) {
        println(-1)
        return
    }
    val union = IntArray(n + 1) { it }
    val wrt = BooleanArray(n + 1) { true }
    fun find(u: Int): Int {
        if (union[union[u]] != union[u]) {
            val v = find(union[u])
            wrt[u] = wrt[u] == wrt[union[u]]
            union[u] = v
        }
        return union[u]
    }
    val segTree = SegmentTree(-1, (2 * n) - 1)
    segTree[-1] = 2 * n
    val prev = IntArray(n + 1) { -1 }
    for ((j, k) in order.withIndex()) {
        //println("k = $k")
        if (prev[k] == -1) {
            prev[k] = j
        } else {
            var a = prev[k]
            var b = prev[k]
            while (true) {
                var upper = a - 1
                var lower = -1
                while (upper > lower) {
                    val mid = (upper + lower + 1) / 2
                    if (segTree[mid, a - 1] > prev[k]) {
                        lower = mid
                    } else {
                        upper = mid - 1
                    }
                }
                val na = lower
                val nb = segTree[na]
                //println("(${prev[k]}, $j) x ($na, $nb)")
                if (na == -1) {
                    break
                }
                if (nb < b) {
                    println(-1)
                    return
                }
                segTree[a] = 0
                a = na
                b = nb
                val u = find(order[a])
                wrt[u] = !wrt[order[a]]
                union[u] = k
            }
            segTree[prev[k]] = j
        }
    }
    val topYes = IntArray(n + 1)
    val topNo = IntArray(n + 1)
    for (k in 1..n) {
        val u = find(k)
        //println("k = $k, u = $u")
        if (wrt[k] == initial[k]) {
            topNo[u]++
        } else {
            topYes[u]++
        }
    }
    //println(wrt.contentToString())
    var answer = 0
    //println(topYes.contentToString())
    //println(topNo.contentToString())
    for (u in 1..n) {
        answer += min(topYes[u], topNo[u])
    }
    println(answer)
}

class SegmentTree(val treeFrom: Int, treeTo: Int) {
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
        var res = 0
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