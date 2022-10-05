import java.util.*
import kotlin.math.max

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val prefixes = LongArray(n + 1)
        val tokenizer = StringTokenizer(readLine()!!)
        for (j in 1..n) {
            prefixes[j] = prefixes[j - 1] + tokenizer.nextToken().toLong()
        }
        val xix = mutableMapOf<Long, Int>()
        for ((j, x) in prefixes.toSet().sorted().withIndex()) {
            xix[x] = j
        }
        val dp = IntArray(n + 1)
        val mapLatest = mutableMapOf<Long, Int>()
        mapLatest[0L] = 0
        val segTree = SegmentTree(0, xix.size - 1)
        segTree.value.fill(Int.MIN_VALUE)
        segTree[xix[0L]!!] = 0
        for (j in 1..n) {
            dp[j] = dp[j - 1] - 1
            val ix = xix[prefixes[j]]!!
            dp[j] = max(dp[j], j + segTree[0, ix - 1])
            if (prefixes[j] in mapLatest) {
                dp[j] = max(dp[j], mapLatest[prefixes[j]]!!)
            }
            mapLatest[prefixes[j]] = dp[j]
            segTree[ix] = max(segTree[ix], dp[j] - j)
        }
        out.appendln(dp[n])
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
            value[node] = max(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromIndex: Int, toIndex: Int): Int {
        if (toIndex < fromIndex) {
            return Int.MIN_VALUE
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Int = Int.MIN_VALUE
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