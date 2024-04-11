import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val k = jin.nextLong()
    val segments = Array(n) { j ->
        val l = jin.nextInt()
        val r = jin.nextInt()
        Segment(j + 1, l, r)
    }
    segments.sort()
    val segTree = LazySegmentTree(1, 200000)
    var m = 0
    val joiner = StringJoiner(" ")
    for (segment in segments) {
        if (segTree.query(segment.l, segment.r) == k) {
            m++
            joiner.add(segment.j.toString())
        } else {
            segTree.update(segment.l, segment.r, 1)
        }
    }
    println(m)
    println(joiner)
}

data class Segment(val j: Int, val l: Int, val r: Int): Comparable<Segment> {
    override fun compareTo(other: Segment) = compareValuesBy(this, other, { it.r }, { it.l })
}

class LazySegmentTree(val treeFrom: Int, val treeTo: Int) {
    val `val`: LongArray
    val lazy: LongArray

    fun combine(a: Long, b: Long): Long {
        return max(a, b)
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

        val IDENTITY = java.lang.Long.MIN_VALUE
    }
}