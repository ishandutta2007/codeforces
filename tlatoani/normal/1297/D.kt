import java.util.*
import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var tokenizer = StringTokenizer(readLine()!!)
        val n = tokenizer.nextToken().toInt()
        var k = tokenizer.nextToken().toLong()
        tokenizer = StringTokenizer(readLine()!!)
        val segTree = LazySegmentTree(1, n)
        val salaries = Array(n) { Pair(it, tokenizer.nextToken().toLong()) }
        salaries.sortBy { it.second }
        for (j in 1..n) {
            segTree.update(j, j, salaries[j - 1].second)
        }
        for (j in 1..n) {
            val jl = j.toLong()
            var curr = segTree.query(j, j)
            var until = if (j == n) 3000000000L else salaries[j].second
            var amt = min(k / jl, until - curr - 1L)
            k -= amt * jl
            segTree.update(1, j, amt)
            if (segTree.query(j, j) + 1L < until && k > 0L) {
                segTree.update(j - k.toInt() + 1, j, 1L)
                k = 0L
            }
        }
        val answer = LongArray(n)
        for (j in 1..n) {
            answer[salaries[j - 1].first] = segTree.query(j, j) - salaries[j - 1].second
        }
        println(answer.joinToString(" "))
    }
}

class LazySegmentTree(val treeFrom: Int, val treeTo: Int) {
    val `val`: LongArray
    val lazy: LongArray
    fun combine(a: Long, b: Long): Long {
        return Math.max(a, b)
    }

    fun propagate(node: Int) {
        `val`[node] += lazy[node]
        if (node shl 1 < `val`.size) {
            lazy[node shl 1] += lazy[node]
            lazy[(node shl 1) + 1] += lazy[node]
        }
        lazy[node] = 0
    }

    fun eval(node: Int): Long {
        return `val`[node] + lazy[node]
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
        `val`[node] = combine(eval(node shl 1), eval((node shl 1) + 1))
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
        `val`[node] = combine(eval(node shl 1), eval((node shl 1) + 1))
        return res
    }

    companion object {
        const val IDENTITY = Long.MIN_VALUE
    }

    init {
        val length = treeTo - treeFrom + 1
        var l: Int
        l = 0
        while (1 shl l < length) {
            l++
        }
        `val` = LongArray(1 shl l + 1)
        lazy = LongArray(1 shl l + 1)
    }
}