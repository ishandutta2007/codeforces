import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, q) = jin.readLine().split(" ").map { it.toInt() }
        val ay = listOf(0L) + jin.readLine().split(" ").map { it.toLong() }.sorted()
        val sums = LongArray(n + 1)
        for (j in 1..n) {
            sums[j] = sums[j - 1] + ay[j]
        }
        val treeSet = TreeMap<Long, Int>()
        for (j in 1..n) {
            treeSet[ay[j]] = j
        }
        val pos = hashSetOf<Long>()
        fun recur(from: Int, to: Int) {
            pos.add(sums[to] - sums[from - 1])
            if (ay[from] != ay[to]) {
                val mean = (ay[from] + ay[to]) / 2L
                val mid = treeSet.floorEntry(mean).value
                recur(from, mid)
                recur(mid + 1, to)
            }
        }
        recur(1, n)
        for (j in 1..q) {
            out.appendln(if (pos.contains(jin.readLine().toLong())) "Yes" else "No")
        }
    }
    print(out)
}