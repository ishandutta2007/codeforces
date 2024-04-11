import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
        val segTree = SegmentTree(1, n)
        for (j in 1..n) {
            segTree[j] = ay[j]
        }
        val prefixes = IntArray(n + 1)
        val suffixes = IntArray(n + 2)
        for (j in 1..n) {
            prefixes[j] = max(prefixes[j - 1], ay[j])
        }
        for (j in n downTo 1) {
            suffixes[j] = max(suffixes[j + 1], ay[j])
        }
        val m = ay.max()!!
        val elems = ay.withIndex().toList().subList(1, n + 1).sortedByDescending { it.value }
        var left = n
        var right = 1
        var leftNext = n
        var rightNext = 1
        var prev = Int.MAX_VALUE
        for ((j, k) in elems) {
            if (k != prev) {
                left = leftNext
                right = rightNext
                prev = k
            }
            val x = min(left, j) - 1
            val w = max(right, j) + 1
            if (prefixes[x] == k && suffixes[w] == k && segTree[x + 1, w - 1] == k) {
                out.appendln("YES").appendln("$x ${w - x - 1} ${n - w + 1}")
                continue@cases
            }
            leftNext = min(leftNext, j)
            rightNext = max(rightNext, j)
        }
        out.appendln("NO")
    }
    print(out)
}

class SegmentTree(val treeFrom: Int, treeTo: Int) {
    val value: IntArray
    val length: Int

    init {
        var e = 0
        while (1 shl e < treeTo - treeFrom + 1) {
            e++
        }
        value = IntArray(1 shl (e + 1))
        length = 1 shl e
    }

    operator fun set(index: Int, delta: Int) {
        var node = index - treeFrom + length
        value[node] = delta
        node = node shr 1
        while (node > 0) {
            value[node] = min(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromIndex: Int, toIndex: Int): Int {
        if (toIndex < fromIndex) {
            return Int.MAX_VALUE
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Int = Int.MAX_VALUE
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