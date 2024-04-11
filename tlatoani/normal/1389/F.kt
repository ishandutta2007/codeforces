import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val xs = mutableListOf<Int>()
    val segments = Array(n) {
        val (l, r, t) = jin.readLine().split(" ").map { it.toInt() }
        xs.add(l)
        xs.add(r)
        Segment(l, r, t - 1)
    }
    xs.sort()
    val xix = mutableMapOf<Int, Int>()
    var k = 0
    var prev = 0
    for (x in xs) {
        if (x != prev) {
            k++
            prev = x
            xix[x] = k
        }
    }
    val segTrees = Array(2) { LazySegmentTree(0, k) }
    segments.sortBy { it.from }
    for (segment in segments) {
        val from = xix[segment.from]!!
        val to = xix[segment.to]!!
        val prev = segTrees[segment.type][to, to]
        val new = max(segTrees[1 - segment.type][0, from - 1], segTrees[segment.type][0, to])
        if (new > prev) {
            segTrees[segment.type].update(to, to, new - prev)
        }
        segTrees[segment.type].update(to, k, 1)
    }
    println(segTrees.map { it[0, k] }.max())
}

data class Segment(val from: Int, val to: Int, val type: Int)

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
            value[node] = lazy[node] + max(
                    update(from, to, segFrom, mid, 2 * node, delta),
                    update(from, to, mid + 1, segTo, (2 * node) + 1, delta)
            )
        }
        return value[node]
    }

    operator fun get(from: Int, to: Int) = query(from, to, treeFrom, treeTo, 1)

    fun query(from: Int, to: Int, segFrom: Int, segTo: Int, node: Int): Int {
        if (from > segTo || to < segFrom) {
            return 0
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

/*

3
1 2 1
3 5 2
4 6 2


 */