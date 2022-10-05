import java.util.*
import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val segTree = SegmentTree(1, 2 * n)
        val tokenizer = StringTokenizer(readLine()!!)
        for (k in 1..n) {
            val x = tokenizer.nextToken().toInt()
            segTree[k] = x
            segTree[k + n] = x
        }
        val g = segTree[1, 2 * n]
        var last = 2 * n
        while (last > n && segTree[n, last - 1] == g) {
            last--
        }
        var answer = last - n
        for (k in n - 1 downTo 1) {
            while (last > k && segTree[k, last - 1] == g) {
                last--
            }
            answer = max(answer, last - k)
        }
        println(answer)
    }
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)

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
            value[node] = gcd(value[node shl 1], value[(node shl 1) + 1])
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
            res = gcd(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = gcd(res, value[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
}