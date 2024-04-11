import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val (n, q) = readLine()!!.split(" ").map { it.toInt() }
    val tokenizerA = StringTokenizer(readLine()!!)
    val tokenizerB = StringTokenizer(readLine()!!)
    val sds = LongArray(n + 1)
    val minSegTree = MinSegmentTree(1, n)
    val maxSegTree = MaxSegmentTree(1, n)
    for (j in 1..n) {
        sds[j] = sds[j - 1] + tokenizerB.nextToken().toLong() - tokenizerA.nextToken().toLong()
        minSegTree[j] = sds[j]
        maxSegTree[j] = sds[j]
    }
    val out = StringBuilder()
    repeat(q) {
        val (l, r) = readLine()!!.split(" ").map { it.toInt() }
        if (sds[l - 1] != sds[r] || minSegTree[l, r] < sds[l - 1]) {
            out.appendln(-1)
        } else {
            out.appendln(maxSegTree[l, r] - sds[l - 1])
        }
    }
    print(out)
}

class MinSegmentTree(val treeFrom: Int, treeTo: Int) {
    val value: LongArray
    val length: Int

    init {
        var e = 0
        while (1 shl e < treeTo - treeFrom + 1) {
            e++
        }
        value = LongArray(1 shl (e + 1))
        length = 1 shl e
    }

    operator fun set(index: Int, delta: Long) {
        var node = index - treeFrom + length
        value[node] = delta
        node = node shr 1
        while (node > 0) {
            value[node] = min(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromIndex: Int, toIndex: Int): Long {
        if (toIndex < fromIndex) {
            return Long.MAX_VALUE
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Long = Long.MAX_VALUE
        while (from + (from and -from) <= to) {
            res = min(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = min(res, value[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
}

class MaxSegmentTree(val treeFrom: Int, treeTo: Int) {
    val value: LongArray
    val length: Int

    init {
        var e = 0
        while (1 shl e < treeTo - treeFrom + 1) {
            e++
        }
        value = LongArray(1 shl (e + 1))
        length = 1 shl e
    }

    operator fun set(index: Int, delta: Long) {
        var node = index - treeFrom + length
        value[node] = delta
        node = node shr 1
        while (node > 0) {
            value[node] = max(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromIndex: Int, toIndex: Int): Long {
        if (toIndex < fromIndex) {
            return Long.MIN_VALUE
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Long = Long.MIN_VALUE
        while (from + (from and -from) <= to) {
            res = max(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = max(res, value[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
}