import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

const val IMPOSSIBLE = -100000000000000000L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val k = jin.readLine().toInt()
    val fs = jin.readLine().split(" ").map { it.toLong() }
    val m = jin.readLine().toInt()
    var dpPrev = LongArray(2) { IMPOSSIBLE }
    dpPrev[0] = 0L
    val segTrees = Array(3) { SegmentTree(0, 100000) }
    for (e in 5 downTo 0) {
        val n = ("1" + "0".repeat(6 - e)).toInt()
        for (t in 0..2) {
            segTrees[t].value.fill(IMPOSSIBLE)
        }
        for (j in 0..n / 10) {
            segTrees[j % 3][j] = dpPrev[j] - (((10 * j) / 3).toLong() * fs[e])
        }
        val dp = LongArray(n + 1) { IMPOSSIBLE }
        for (j in 0..n) {
            for (t in 0..2) {
                val correction = if ((j % 3) >= t) 0L else -1L
                dp[j] = max(dp[j], segTrees[t][(j - (9 * (k - 1)) + 9) / 10, j / 10] + (fs[e] * ((j / 3).toLong() + correction)))
                for (j2 in j - (9 * k) until j - (9 * (k - 1))) {
                    if (j2 >= 0 && j2 % 10 == 0) {
                        if ((j - j2) % 3 == 0) {
                            dp[j] = max(dp[j], segTrees[t][j2 / 10] + (fs[e] * ((j / 3).toLong() + correction)))
                        } else {
                            val cancel = ((j - (9 * (k - 1)) - j2) / 3).toLong()
                            dp[j] = max(dp[j], segTrees[t][j2 / 10] + (fs[e] * ((j / 3).toLong() + correction - cancel)))
                        }
                    }
                }
            }
            if (dp[j] < 0L) {
                dp[j] = IMPOSSIBLE
            }
        }
        dpPrev = dp
    }
    val out = StringBuilder()
    for (j in 1..m) {
        out.appendln(dpPrev[jin.readLine().toInt()])
    }
    println(out)
}

class SegmentTree(val treeFrom: Int, val treeTo: Int) {
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
            return IMPOSSIBLE
        }

        var from = max(treeFrom, fromIndex) + length - treeFrom
        var to = min(treeTo, toIndex) + length - treeFrom + 1
        var res = IMPOSSIBLE
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