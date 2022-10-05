import java.lang.StringBuilder
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val minST = LazyMinSegmentTree(1, 1000000)
    val maxST = LazyMaxSegmentTree(1, 1000000)
    var j = 1
    var sum = 0
    val joiner = StringJoiner(" ")
    jin.nextInt()
    val text = IntArray(1000001)
    for (command in jin.next()) {
        if (command == 'L') {
            j = max(1, j - 1)
        } else if (command == 'R') {
            j++
        } else {
            val d = when (command) {
                '(' -> 1
                ')' -> -1
                else -> 0
            } - text[j]
            text[j] += d
            sum += d
            minST.update(j, 1000000, d.toLong())
            maxST.update(j, 1000000, d.toLong())
        }
        if (sum != 0 || minST.query(1, 1000000) != 0L) {
            joiner.add("-1")
        } else {
            joiner.add(maxST.query(1, 1000000).toString())
        }
    }
    println(joiner)
}

class LazyMinSegmentTree(val treeFrom: Int, val treeTo: Int) {
    val `val`: LongArray
    val lazy: LongArray
    fun combine(a: Long, b: Long): Long {
        return min(a, b)
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
        const val IDENTITY = Long.MAX_VALUE
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

class LazyMaxSegmentTree(val treeFrom: Int, val treeTo: Int) {
    val `val`: LongArray
    val lazy: LongArray
    fun combine(a: Long, b: Long): Long {
        return a.coerceAtLeast(b)
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