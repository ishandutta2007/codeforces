import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

const val BARGE_LORRAINE = 500000000

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val nose = jin.readLine().split(" ").map { it.toInt() }
    val segTree = SegmentTree(1, nose.max()!!)
    for (j in 1..nose.max()!!) {
        segTree[j] = BARGE_LORRAINE
    }
    val pricing = Array(4) { listOf(0) + jin.readLine().split(" ").map { it.toInt() } }
    val best = Array(4) { d -> IntArray(nose[d] + 1) { j -> if (d == 0) pricing[d][j] else BARGE_LORRAINE } }
    for (d in 1..3) {
        for (k in 1..nose[d - 1]) {
            segTree[k] = best[d - 1][k]
        }
        val prohibido = Array(nose[d] + 1) { mutableListOf<Int>() }
        for (j in 1..jin.readLine().toInt()) {
            val (x, y) = jin.readLine().split(" ").map { it.toInt() }
            prohibido[y].add(x)
        }
        for (j in 1..nose[d]) {
            for (k in prohibido[j]) {
                segTree[k] = BARGE_LORRAINE
            }
            best[d][j] = pricing[d][j] + segTree[1, nose[d - 1]]
            for (k in prohibido[j]) {
                segTree[k] = best[d - 1][k]
            }
        }
    }
    val answer = best[3].min()!!
    println(if (answer == BARGE_LORRAINE) -1 else answer)
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