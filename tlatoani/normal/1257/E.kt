import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val k = IntArray(3) { jin.nextInt() }
    val n = k.sum()
    val problems = IntArray(k.sum())
    for (j in 0..2) {
        for (l in 1..k[j]) {
            problems[jin.nextInt() - 1] = j
        }
    }
    val segTree = LazySegmentTree(0, n)
    var curr = k[0] + k[1]
    var answer = curr
    for (j in 0 until n) {
        when (problems[j]) {
            0 -> segTree.update(j + 1, n, -1)
            1 -> { curr--; segTree.update(j + 1, n, 1) }
            2 -> curr++
        }
        answer = min(answer, curr + segTree.query(0, n).toInt())
    }
    println(answer)
}

class LazySegmentTree(val treeFrom: Int, val treeTo: Int) {
    val array: LongArray
    val lazy: LongArray

    fun combine(a: Long, b: Long): Long {
        return min(a, b)
    }

    init {
        val length = treeTo - treeFrom + 1
        var l: Int
        l = 0
        while (1 shl l < length) {
            l++
        }
        array = LongArray(1 shl l + 1)
        lazy = LongArray(1 shl l + 1)
    }

    fun propagate(node: Int) {
        array[node] += lazy[node]
        if (node shl 1 < array.size) {
            lazy[node shl 1] += lazy[node]
            lazy[(node shl 1) + 1] += lazy[node]
        }
        lazy[node] = 0
    }

    fun eval(node: Int): Long {
        return array[node] + lazy[node]
    }

    fun update(from: Int, to: Int, delta: Long) {
        update(1, treeFrom, treeTo, from, to, delta)
    }

    fun update(node: Int, segFrom: Int, segTo: Int, from: Int, to: Int, delta: Long) {
        if (segTo < from || segFrom > to) return
        if (segFrom >= from && segTo <= to) {
            lazy[node] += delta
            return
        }
        propagate(node)
        val mid = segFrom + segTo shr 1
        update(node shl 1, segFrom, mid, from, to, delta)
        update((node shl 1) + 1, mid + 1, segTo, from, to, delta)
        array[node] = combine(eval(node shl 1), eval((node shl 1) + 1))
    }

    fun query(from: Int, to: Int): Long {
        return query(1, treeFrom, treeTo, from, to)
    }

    fun query(node: Int, segFrom: Int, segTo: Int, from: Int, to: Int): Long {
        if (segTo < from || segFrom > to) return IDENTITY
        if (segFrom >= from && segTo <= to) {
            return eval(node)
        }
        propagate(node)
        val mid = segFrom + segTo shr 1
        val res = combine(
                query(node shl 1, segFrom, mid, from, to),
                query((node shl 1) + 1, mid + 1, segTo, from, to)
        )
        array[node] = combine(eval(node shl 1), eval((node shl 1) + 1))
        return res
    }

    companion object {

        val IDENTITY = java.lang.Long.MIN_VALUE
    }
}