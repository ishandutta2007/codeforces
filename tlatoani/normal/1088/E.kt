import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val weights = LongArray(n + 1) { if (it == 0) 0L else tokenizer.nextToken().toLong() }
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        val line = jin.readLine()
        val a = line.substringBefore(' ').toInt()
        val b = line.substringAfter(' ').toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val parent = IntArray(n + 1)
    val dp = LongArray(n + 1) { weights[it] }
    var m = Long.MIN_VALUE
    val dfs = IntArray(n)
    var j = 0
    fun dfs1(a: Int) {
        for (b in adj[a]) {
            if (parent[a] != b) {
                parent[b] = a
                dfs1(b)
                if (dp[b] > 0L) {
                    dp[a] += dp[b]
                }
            }
        }
        dfs[j] = a
        j++
        m = max(m, dp[a])
    }
    dfs1(1)
    var k = 0L
    for (a in dfs) {
        dp[a] = weights[a]
        for (b in adj[a]) {
            if (parent[a] != b && dp[b] > 0L) {
                dp[a] += dp[b]
            }
        }
        if (dp[a] == m) {
            k++
            dp[a] = 0L
        }
    }
    println("${k * m} $k")
}