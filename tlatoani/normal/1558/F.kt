import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val p = (listOf(0) + readLine()!!.split(" ").map { it.toInt() }).toMutableList()
        if (p == (0..n).toList()) {
            println(0)
        } else {
            for (j in 1 until n step 2) {
                if (p[j] > p[j + 1]) {
                    val a = p[j]
                    val b = p[j + 1]
                    p[j] = b
                    p[j + 1] = a
                }
            }
            var answer = 0
            val q = (0..n).sortedBy { p[it] }
            val segTree = LazySegmentTree(1, n + 1)
            for (j in 1..n) {
                segTree.update(1, j, 1)
            }
            var last0 = 0
            var first1 = 1
            for (k in 1 until n) {
                last0 = max(last0, q[k])
                while (p[first1] <= k) {
                    first1++
                }
                if (first1 < last0) {
                    segTree.update(1, q[k], -2)
                    answer = max(answer, (last0 - k) - (segTree[first1, last0] - segTree[last0 + 1, last0 + 1]) - 1)
                }
            }
            answer++
            println(answer)
        }
    }
}

const val BILLION = 1000000000

class LazySegmentTree(val treeFrom: Int, val treeTo: Int) {
    val value: IntArray
    val lazy: IntArray

    init {
        val length = treeTo - treeFrom + 1
        var e = 0
        while (1 shl e < length) {
            e++
        }
        value = IntArray(1 shl (e + 1))
        lazy = IntArray(1 shl (e + 1))
    }

    fun update(from: Int, to: Int, delta: Int) {
        update(from, to, treeFrom, treeTo, 1, delta)
    }

    fun update(from: Int, to: Int, segFrom: Int, segTo: Int, node: Int, delta: Int): Int {
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

    fun query(from: Int, to: Int, segFrom: Int, segTo: Int, node: Int): Int {
        if (from > segTo || to < segFrom) {
            return BILLION
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