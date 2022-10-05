import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, q) = jin.readLine().split(" ").map { it.toInt() }
    val pInv = IntArray(n + 1)
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..n) {
        pInv[tokenizer.nextToken().toInt()] = j
    }
    val ay = listOf(0) + jin.readLine().split(" ").map { pInv[it.toInt()] }
    val prev = mutableMapOf<Int, Int>()
    val dp = Array(18) { IntArray(m + 1) }
    for (j in 1..m) {
        val k = if (ay[j] == 1) n else (ay[j] - 1)
        if (k in prev) {
            dp[0][j] = prev[k]!!
        }
        for (e in 1..17) {
            dp[e][j] = dp[e - 1][dp[e - 1][j]]
        }
        prev[ay[j]] = j
    }
    val segTree = SegmentTree(1, m)
    for (j in 1..m) {
        var k = j
        for (e in 17 downTo 0) {
            if ((n - 1) and (1 shl e) != 0) {
                k = dp[e][k]
            }
        }
        segTree[j] = k
    }
    val out = StringBuilder()
    for (j in 1..q) {
        val (l, r) = jin.readLine().split(" ").map { it.toInt() }
        if (segTree[l, r] >= l) {
            out.append(1)
        } else {
            out.append(0)
        }
    }
    println(out)
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
            return 0
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Int = 0
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