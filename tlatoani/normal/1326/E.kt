import java.util.*
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    var tokenizer = StringTokenizer(readLine()!!)
    val p = IntArray(n + 1) { if (it == 0) 0 else tokenizer.nextToken().toInt() }
    tokenizer = StringTokenizer(readLine()!!)
    val q = IntArray(n) {  tokenizer.nextToken().toInt() }
    val pr = IntArray(n + 1)
    for (j in 1..n) {
        pr[p[j]] = j
    }
    val answer = IntArray(n)
    val segTree = LazySegmentTree(1, n)
    var k = n
    for (j in 0 until n) {
        segTree.update(1, pr[k], -1L)
        while (segTree[1, n] >= 0L) {
            k--
            segTree.update(1, pr[k], -1L)
        }
        segTree.update(1, pr[k], 1L)
        answer[j] = k
        segTree.update(1, q[j], 1L)
    }
    println(answer.joinToString(" "))
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