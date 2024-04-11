import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        val tokenizer = StringTokenizer(jin.readLine())
        for (a in 2..n) {
            val b = tokenizer.nextToken().toInt()
            adj[a].add(b)
            adj[b].add(a)
        }
        val ay = listOf(0L, 0L) + jin.readLine().split(" ").map { it.toLong() }
        val parent = IntArray(n + 1)
        val atDepth = Array(n) { mutableListOf<Int>() }
        fun dfs(a: Int, d: Int) {
            atDepth[d].add(a)
            for (b in adj[a]) {
                if (b != parent[a]) {
                    parent[b] = a
                    dfs(b, d + 1)
                }
            }
        }
        dfs(1, 0)
        val dp = LongArray(n + 1)
        for (d in n - 1 downTo 1) {
            atDepth[d].sortBy { ay[it] }
            val before = TreeSet<Node>(compareBy({ it.score }, { it.a }))
            val after = TreeSet<Node>(compareBy({ it.score }, { it.a }))
            for (a in atDepth[d]) {
                after.add(Node(a, dp[a] + ay[a]))
            }
            for (a in atDepth[d]) {
                before.add(Node(a, dp[a] - ay[a]))
                dp[parent[a]] = maxOf(dp[parent[a]],
                        max(before.last()!!.score + ay[a], after.last()!!.score - ay[a]),
                        max(dp[a] + ay[a] - ay[atDepth[d][0]], dp[a] + ay[atDepth[d].last()] - ay[a]))
                after.remove(Node(a, dp[a] + ay[a]))
            }
        }
        out.appendln(dp[1])
    }
    print(out)
}

data class Node(val a: Int, val score: Long)