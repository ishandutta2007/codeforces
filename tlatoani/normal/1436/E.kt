import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val last = SegmentTree(1, n + 1)
    var is1 = true
    val seen = BooleanArray(n + 3)
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        if (k != 1) {
            is1 = false
        }
        if (last[1, k - 1] > last[k]) {
            seen[k] = true
        }
        last[k] = j
    }
    for (k in 1..n + 1) {
        if (last[1, k - 1] > last[k]) {
            seen[k] = true
        }
    }
    if (is1) {
        seen[1] = false
    }
    for (answer in 1..n + 2) {
        if (!seen[answer]) {
            println(answer)
            return
        }
    }
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