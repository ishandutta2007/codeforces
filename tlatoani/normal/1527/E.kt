import java.util.*
import kotlin.math.min

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val segTree = LazySegmentTree(k, 0, n)
    segTree.update(1, n, LongArray( k + 1) { 10000000000000000L })
    val tokenizer = StringTokenizer(readLine()!!)
    val last = mutableMapOf<Int, Int>()
    for (r in 1..n) {
        val j = tokenizer.nextToken().toInt()
        val l = last[j]
        if (l != null) {
            segTree.update(0, l - 1, LongArray(k + 1) { (r - l).toLong() })
        }
        last[j] = r
        val query = segTree[0, r - 1]
        segTree.update(r, r, LongArray(k + 1) { if (it == 0) 0L else query[it - 1] - 10000000000000000L })
    }
    println(segTree[n, n][k])
}

class LazySegmentTree(val k: Int, val treeFrom: Int, val treeTo: Int) {
    val value: Array<LongArray>
    val lazy: Array<LongArray>

    init {
        val length = treeTo - treeFrom + 1
        var e = 0
        while (1 shl e < length) {
            e++
        }
        value = Array(1 shl (e + 1)) { LongArray(k + 1) }
        lazy = Array(1 shl (e + 1)) { LongArray(k + 1) }
    }

    fun update(from: Int, to: Int, delta: LongArray) {
        update(from, to, treeFrom, treeTo, 1, delta)
    }

    fun update(from: Int, to: Int, segFrom: Int, segTo: Int, node: Int, delta: LongArray) {
        if (from > segTo || to < segFrom) {

        } else if (from <= segFrom && to >= segTo) {
            for (x in 0..k) {
                value[node][x] += delta[x]
                lazy[node][x] += delta[x]
            }
        } else {
            val mid = (segFrom + segTo) / 2
            val left = 2 * node
            val right = (2 * node) + 1
            update(from, to, segFrom, mid, left, delta)
            update(from, to, mid + 1, segTo, right, delta)
            for (x in 0..k) {
                value[node][x] = lazy[node][x] + min(value[left][x], value[right][x])
            }
        }
    }

    operator fun get(from: Int, to: Int): LongArray {
        val res = LongArray(k + 1) { Long.MAX_VALUE }
        val add = LongArray(k + 1)
        query(from, to, treeFrom, treeTo, 1, res, add)
        //println("$from $to " + res.contentToString())
        return res
    }

    fun query(from: Int, to: Int, segFrom: Int, segTo: Int, node: Int, res: LongArray, add: LongArray) {
        if (from > segTo || to < segFrom) {

        } else if (from <= segFrom && to >= segTo) {
            for (x in 0..k) {
                res[x] = min(res[x], add[x] + value[node][x])
            }
        } else {
            val mid = (segFrom + segTo) / 2
            for (x in 0..k) {
                add[x] += lazy[node][x]
            }
            query(from, to, segFrom, mid, 2 * node, res, add)
            query(from, to, mid + 1, segTo, (2 * node) + 1, res, add)
            for (x in 0..k) {
                add[x] -= lazy[node][x]
            }
        }
    }
}