import java.util.*
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val p = IntArray(n + 1)
    val pos = IntArray(n + 1)
    var tokenizer = StringTokenizer(readLine()!!)
    for (j in 1..n) {
        p[j] = tokenizer.nextToken().toInt()
        pos[p[j]] = j
    }
    tokenizer = StringTokenizer(readLine()!!)
    val a = LongArray(n + 1)
    for (j in 1..n) {
        a[p[j]] = tokenizer.nextToken().toLong()
    }
    val segTree = LazySegmentTree(0, n)
    for (j in 1..n) {
        segTree.update(pos[j], n, a[j])
    }
    var answer = segTree.query(1, n - 1)
    for (j in 1..n) {
        segTree.update(pos[j], n, -a[j])
        segTree.update(0, pos[j] - 1, a[j])
        answer = min(answer, segTree.query(1, n - 1))
    }
    println(answer)
}

class LazySegmentTree(val treeFrom: Int, val treeTo: Int) {
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