import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = jin.readLine().split(" ").map { it.toInt() }
    val ay = listOf(-n) + jin.readLine().split(" ").withIndex().map { (j, x) -> x.toInt() - j } + listOf(1000000000)
    val locked = listOf(0) + (if (k == 0) listOf() else jin.readLine().split(" ").map { it.toInt() }) + listOf(n + 1)
    if ((1 until locked.size).any { ay[locked[it - 1]] > ay[locked[it]] }) {
        println(-1)
        return
    }
    var answer = n - k
    val segTree = SegmentTree(1, n)
    fun lnds(elems: List<Int>): Int {
        if (elems.isEmpty()) {
            return 0
        }
        val xs = elems.sorted()
        val xix = mutableMapOf<Int, Int>()
        var ix = 0
        var last = xs.first() - 1
        for (x in xs) {
            if (x != last) {
                ix++
                xix[x] = ix
                last = x
            }
        }
        for (j in 1..ix) {
            segTree[j] = 0
        }
        for (x in elems) {
            val j = xix[x]!!
            segTree[j] = segTree[1, j] + 1
        }
        return segTree[1, ix]
    }
    for (j in 1 until locked.size) {
        val elems = mutableListOf<Int>()
        for (j2 in locked[j - 1] + 1 until locked[j]) {
            if (ay[j2] in ay[locked[j - 1]]..ay[locked[j]]) {
                elems.add(ay[j2])
            }
        }
        answer -= lnds(elems)
    }
    println(answer)
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
        var res = 0
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