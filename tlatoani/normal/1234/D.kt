import java.lang.StringBuilder
import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val s = jin.nextLine()
    val segTree = SegmentTree(1, s.length)
    for (i in 1..s.length) {
        segTree.update(i, 1 shl (s[i - 1] - 'a'))
    }
    val dp = IntArray(1 shl 13)
    for (i in 1 until (1 shl 13)) {
        dp[i] = dp[i - (i and -i)] + 1
    }
    val AND = (1 shl 13) - 1
    val builder = StringBuilder()
    for (qq in 1..jin.nextInt()) {
        if (jin.nextInt() == 1) {
            val pos = jin.nextInt()
            segTree.update(pos, 1 shl (jin.next()[0] - 'a'))
        } else {
            val from = jin.nextInt()
            val to = jin.nextInt()
            val query = segTree.query(from, to)
            builder.append(dp[query and AND] + dp[query shr 13])
            builder.append('\n')
        }
    }
    print(builder)
}

class SegmentTree(val treeFrom: Int, treeTo: Int) {
    val array: IntArray
    val length: Int

    init {
        val length = treeTo - treeFrom + 1
        var l = 0
        while (1 shl l < length) {
            l++
        }
        array = IntArray(1 shl l + 1)
        this.length = 1 shl l
    }

    fun update(index: Int, newVal: Int) {
        var node = index - treeFrom + length
        array[node] = newVal
        node = node shr 1
        while (node > 0) {
            array[node] = array[node shl 1] or array[(node shl 1) + 1]
            node = node shr 1
        }
    }

    fun query(from: Int, to: Int): Int {
        var from = from
        var to = to
        if (to < from) {
            return 0
        }
        from += length - treeFrom
        to += length - treeFrom + 1
        var res = 0
        while (from + (from and -from) <= to) {
            res = res or array[from / (from and -from)]
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = res or array[(to - (to and -to)) / (to and -to)]
            to -= to and -to
        }
        return res
    }
}