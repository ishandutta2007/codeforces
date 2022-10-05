import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val intervals = Array(n + 1) { if (it == 0) Pair(0L, 0L) else {
            val (l, r) = jin.readLine().split(" ").map { it.toLong() }
            Pair(l, r)
        } }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 2..n) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        fun recur(a: Int, parent: Int): Pair<Long, Long> {
            var left = 0L
            var right = 0L
            val (l, r) = intervals[a]
            for (b in adj[a]) {
                if (b != parent) {
                    val (x, y) = recur(b, a)
                    val (t, u) = intervals[b]
                    left += max(x + abs(l - t), y + abs(l - u))
                    right += max(x + abs(r - t), y + abs(r - u))
                }
            }
            return Pair(left, right)
        }
        val (x, y) = recur(1, 0)
        out.appendln(max(x, y))
    }
    print(out)
}