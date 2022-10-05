import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val adj = Array(n + 1) { mutableSetOf<Int>() }
        for (j in 2..n) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        var answer = 1
        fun recur(a: Int): Int {
            var best1 = 0
            var best2 = 0
            for (b in adj[a]) {
                adj[b].remove(a)
                val dp = recur(b)
                if (dp > best1) {
                    best2 = best1
                    best1 = dp
                } else if (dp > best2) {
                    best2 = dp
                }
            }
            if (adj[a].size == 1) {
                answer = max(answer, 1 + best1 + (if (a == 1) 0 else 1))
            } else if (adj[a].size > 1) {
                answer = max(answer, 1 + best1 + best2 + adj[a].size - 2 + (if (a == 1) 0 else 1))
            }
            return if (adj[a].isEmpty()) 1 else (1 + best1 + adj[a].size - 1)
        }
        recur(1)
        out.appendln(answer)
    }
    print(out)
}