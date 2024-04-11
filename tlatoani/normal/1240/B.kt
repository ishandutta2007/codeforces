import java.lang.StringBuilder
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val builder = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val firstIx = IntArray(n + 1)
        val maxSegTree = MaxSegmentTree(1, n)
        var minThing = n
        for (i in 1..n) {
            val k = jin.nextInt()
            minThing = min(minThing, k)
            if (firstIx[k] == 0) {
                firstIx[k] = i
            }
            maxSegTree.update(k, i)
        }
        var maxMid = 0
        var curr = 1
        var l = minThing
        var amtDistinct = 0
        for (k in minThing..n) {
            if (firstIx[k - 1] != 0) {
                curr--
            }
            if (firstIx[k] != 0) {
                amtDistinct++
            }
            while (l < n) {
                //println("k = $k, l = $l, curr = $curr")
                if (firstIx[l + 1] == 0) {
                    l++
                } else if (maxSegTree.query(k, l) < firstIx[l + 1]) {
                    l++
                    curr++
                } else {
                    break
                }
            }
            //println("k = $k, l = $l, curr = $curr")
            maxMid = max(maxMid, curr)
        }
        //println("maxMid = $maxMid")
        //println("amtDistinct = $amtDistinct")
        builder.append(amtDistinct - maxMid)
        builder.append('\n')
    }
    print(builder)
}
class MaxSegmentTree(val treeFrom: Int, treeTo: Int) {
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
            array[node] = max(array[node shl 1], array[(node shl 1) + 1])
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
            res = max(res, array[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = max(res, array[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
}