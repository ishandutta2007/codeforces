import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val segTree = LazySegmentTree(1, n)
    val array = listOf(Long.MIN_VALUE) + jin.readLine().split(" ").map { it.toLong() }
    for (j in 1..n) {
        segTree.update(j, j, array[j])
    }
    val toRemove = Array(n + 2) { mutableListOf<Interval>() }
    val toAdd = Array(n + 2) { mutableListOf<Interval>() }
    for (j in 1..m) {
        val (from, to) = jin.readLine().split(" ").map { it.toInt() }
        val interval = Interval(j, from, to)
        segTree.update(from, to, -1L)
        toRemove[from].add(interval)
        toAdd[to + 1].add(interval)
    }
    var answer = 0L
    for (j in 1..n) {
        for (interval in toRemove[j]) {
            segTree.update(interval.from, interval.to, 1L)
        }
        for (interval in toAdd[j]) {
            segTree.update(interval.from, interval.to, -1L)
        }
        answer = max(answer, array[j] - segTree[1, n])
    }
    for (interval in toAdd[n + 1]) {
        segTree.update(interval.from, interval.to, -1L)
    }
    val used = (1..m).toMutableSet()
    for (j in 1..n) {
        for (interval in toRemove[j]) {
            segTree.update(interval.from, interval.to, 1L)
            used.remove(interval.ix)
        }
        for (interval in toAdd[j]) {
            segTree.update(interval.from, interval.to, -1L)
            used.add(interval.ix)
        }
        if (array[j] - segTree[1, n] == answer) {
            println(answer)
            println(used.size)
            println(used.joinToString(" "))
            return
        }
    }
}

data class Interval(val ix: Int, val from: Int, val to: Int)

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