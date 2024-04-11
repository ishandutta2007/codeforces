import kotlin.math.min

fun main() {
    val (q, x1, y1) = readLine()!!.split(" ").map { it.toInt() }
    val tons = LongArray(q + 2)
    val costs = LongArray(q + 2)
    tons[1] = x1.toLong()
    costs[1] = y1.toLong()
    val ancestors = Array(q + 2) { IntArray(19) }
    val depth = IntArray(q + 2)
    fun ancestor(a: Int, d: Int): Int {
        var res = a
        for (j in 18 downTo 0) {
            if (1 shl j <= depth[res] - d) {
                res = ancestors[res][j]
            }
        }
        return res
    }
    fun highestAncestorDepth(a: Int): Int {
        var a = a
        for (j in 18 downTo 0) {
            if (tons[ancestors[a][j]] > 0L) {
                a = ancestors[a][j]
            }
        }
        return depth[a]
    }
    for (a in 2..q + 1) {
        val line = readLine()!!.split(" ").map { it.toInt() }
        if (line[0] == 1) {
            val (_, parent, x, y) = line
            ancestors[a][0] = parent + 1
            for (j in 1..18) {
                ancestors[a][j] = ancestors[ancestors[a][j - 1]][j - 1]
            }
            depth[a] = depth[parent + 1] + 1
            tons[a] = x.toLong()
            costs[a] = y.toLong()
        } else {
            var (_, b, w) = line
            b++
            var amt = w.toLong()
            var amtBought = 0L
            var spent = 0L
            for (d in highestAncestorDepth(b)..depth[b]) {
                val c = ancestor(b, d)
                val here = min(amt, tons[c])
                amt -= here
                tons[c] -= here
                amtBought += here
                spent += costs[c] * here
                if (amt == 0L) {
                    break
                }
            }
            println("$amtBought $spent")
        }
    }
}