import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        var tokenizer = StringTokenizer(jin.readLine())
        val n = tokenizer.nextToken().toInt()
        val m = tokenizer.nextToken().toInt()
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        val c = tokenizer.nextToken().toInt()
        tokenizer = StringTokenizer(jin.readLine())
        val prices = arrayOf(0L) + Array(m) { tokenizer.nextToken().toLong() }
        prices.sort()
        for (j in 1..m) {
            prices[j] += prices[j - 1]
        }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 1..m) {
            tokenizer = StringTokenizer(jin.readLine())
            val x = tokenizer.nextToken().toInt()
            val y = tokenizer.nextToken().toInt()
            adj[x].add(y)
            adj[y].add(x)
        }
        val distsA = bfs(a, adj)
        val distsB = bfs(b, adj)
        val distsC = bfs(c, adj)
        var answer = Long.MAX_VALUE
        for (x in 1..n) {
            if (distsA[x] + distsB[x] + distsC[x] <= m) {
                answer = min(answer, prices[distsB[x]] + prices[distsA[x] + distsB[x] + distsC[x]])
            }
        }
        out.appendln(answer)
    }
    print(out)
}

fun bfs(r: Int, adj: Array<out List<Int>>): IntArray {
    val dists = IntArray(adj.size) { -1 }
    dists[r] = 0
    val q = LinkedList<Int>()
    q.add(r)
    while (q.isNotEmpty()) {
        val a = q.remove()
        for (b in adj[a]) {
            if (dists[b] < 0) {
                dists[b] = dists[a] + 1
                q.add(b)
            }
        }
    }
    return dists
}