import java.lang.StringBuilder
import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val builder = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val segTree = SegmentTree(1, n)
        for (j in 1..n) {
            segTree.update(j, jin.nextLong())
        }
        val m = jin.nextInt()
        val heroes = TreeMap<Int, Int>()
        for (j in 1..m) {
            val p = jin.nextInt()
            val s = jin.nextInt()
            if (heroes.ceilingEntry(s) == null || p > heroes.ceilingEntry(s).value) {
                while (heroes.floorEntry(s) != null && heroes.floorEntry(s).value <= p) {
                    heroes.remove(heroes.floorKey(s))
                }
                heroes[s] = p
            }
        }
        if (heroes.firstEntry().value < segTree.query(1, n)) {
            builder.append("-1\n")
            continue
        }
        val dp = IntArray(n + 1)
        for (j in 1..n) {
            var lower = max(j - heroes.lastKey(), 0)
            var upper = j - 1
            while (upper > lower) {
                val mid = (lower + upper) / 2
                if (heroes.ceilingEntry(j - mid).value >= segTree.query(mid + 1, j)) {
                    upper = mid
                } else {
                    lower = mid + 1
                }
            }
            dp[j] = dp[upper] + 1
        }
        builder.append(dp[n])
        builder.append('\n')
    }
    print(builder)
}

class SegmentTree(val treeFrom: Int, treeTo: Int) {
    val `val`: LongArray
    val length: Int

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

    fun update(index: Int, delta: Long) {
        var node = index - treeFrom + length
        `val`[node] += delta
        node = node shr 1
        while (node > 0) {
            `val`[node] = max(`val`[node shl 1], `val`[(node shl 1) + 1])
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
        var res: Long = 0
        while (from + (from and -from) <= to) {
            res = max(res, `val`[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = max(res, `val`[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
}