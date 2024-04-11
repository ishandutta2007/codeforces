import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var tokenizer = StringTokenizer(jin.readLine())
        val n = tokenizer.nextToken().toInt()
        val m = tokenizer.nextToken().toInt()
        val k = tokenizer.nextToken().toInt()
        tokenizer = StringTokenizer(jin.readLine())
        val array = IntArray(n) { tokenizer.nextToken().toInt() }
        val segTree = SegmentTree(0, n - 1)
        for (j in 0 until m) {
            segTree.update(j, max(array[j], array[j + n - m]).toLong())
        }
        var answer = 0
        var d = min(k, m - 1)
        d = m - 1 - d
        for (j in 0 until m - d) {
            answer = max(answer, segTree.query(j, j + d).toInt())
        }
        println(answer)
    }
}

internal class SegmentTree(val treeFrom: Int, treeTo: Int) {
    val `val`: LongArray
    val length: Int
    fun update(index: Int, delta: Long) {
        var node = index - treeFrom + length
        `val`[node] = delta
        node = node shr 1
        while (node > 0) {
            `val`[node] = min(`val`[node shl 1], `val`[(node shl 1) + 1])
            node = node shr 1
        }
    }

    fun query(from: Int, to: Int): Long {
        var from = from
        var to = to
        if (to < from) {
            return 0
        }
        from += length - treeFrom
        to += length - treeFrom + 1
        var res: Long = Long.MAX_VALUE
        while (from + (from and -from) <= to) {
            res = min(res, `val`[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = min(res, `val`[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }

    init {
        val length = treeTo - treeFrom + 1
        var l: Int
        l = 0
        while (1 shl l < length) {
            l++
        }
        `val` = LongArray(1 shl l + 1)
        this.length = 1 shl l
    }
}