import java.util.*
import kotlin.math.max

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val d = line.substring(six + 1).toLong()
    val tokenizer = StringTokenizer(readLine()!!)
    val trans = LongArray(n) { tokenizer.nextToken().toLong() }
    val segTree = LazySegmentTree(0, n - 1)
    var curr = 0L
    for (j in 0 until n) {
        curr += trans[j]
        segTree.update(j, j, curr)
    }
    if (segTree[0, n - 1] > d) {
        println(-1)
        return
    }
    var answer = 0
    for (j in 0 until n) {
        if (trans[j] == 0L) {
            val deficit = -segTree[j, j]
            if (deficit > 0L) {
                val deposit = d - segTree[j, n - 1]
                if (deposit < deficit) {
                    println(-1)
                    return
                }
                segTree.update(j, n - 1, deposit)
                answer++
            }
        }
    }
    println(answer)
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
            return Long.MIN_VALUE
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