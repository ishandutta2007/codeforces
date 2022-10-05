import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k, m) = jin.readLine().split(" ").map { it.toInt() }
    val segTree = LazySegmentTree(1, 700000)
    for (j in 1..700000) {
        segTree.update(j, j, (1 - j).toLong())
    }

    val treeSet = TreeSet<Pawn>(compareBy({ it.z }, { it.y }, { it.x }))
    val out = StringBuilder()
    for (j in 1..m) {
        val (x, y) = jin.readLine().split(" ").map { it.toInt() }
        val z = y + abs(k - x)
        val pawn = Pawn(x, y, z)
        if (pawn in treeSet) {
            treeSet.remove(pawn)
            segTree.update(1, z, 1L)
        } else {
            treeSet.add(pawn)
            segTree.update(1, z, -1L)
        }
        if (treeSet.isEmpty()) {
            out.appendln(0)
        } else {
            var upper = 700000
            var lower = max(n, treeSet.last().z)
            while (upper > lower) {
                val mid = (upper + lower) / 2
                if (segTree[1, mid] >= -mid) {
                    upper = mid
                } else {
                    lower = mid + 1
                }
            }
            out.appendln(upper - n)
        }
    }
    print(out)
}

data class Pawn(val x: Int, val y: Int, val z: Int)

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