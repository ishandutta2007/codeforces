import kotlin.math.min

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val segments = Array(n) {
        val (l, r, w) = readLine()!!.split(" ").map { it.toInt() }
        Segment(l, r, w)
    }
    segments.sortBy { it.value }
    val segTree = LazySegmentTree(1, m - 1)
    var r = -1
    var answer = Int.MAX_VALUE
    for (l in 0 until n) {
        while (segTree[1, m - 1] == 0) {
            r++
            if (r == n) {
                break
            }
            segTree.update(segments[r].from, segments[r].to - 1, 1)
        }
        if (r == n) {
            break
        }
        answer = min(answer, segments[r].value - segments[l].value)
        segTree.update(segments[l].from, segments[l].to - 1, -1)
    }
    println(answer)
}

data class Segment(val from: Int, val to: Int, val value: Int)

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
            return Int.MAX_VALUE
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