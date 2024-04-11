import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val m = (n * (n - 1)) / 2
    val edges = Array(m) { Pair(0, 0) }
    for (j in 1..n) {
        val tokenizer = StringTokenizer(jin.readLine())
        for (k in 1..n) {
            val x = tokenizer.nextToken().toInt()
            if (x != 0) {
                edges[x - 1] = Pair(j, k)
            }
        }
    }
    val union = IntArray(2 * n) { it }
    val children = Array(2 * n) { mutableListOf<Int>() }
    val amtNodes = IntArray(2 * n) { 1 }
    val amtEdges = IntArray(2 * n)
    fun find(u: Int): Int {
        if (union[u] != union[union[u]]) {
            union[u] = find(union[u])
        }
        return union[u]
    }
    var y = n
    val candidates = (1..n).toMutableList()
    for (edge in edges) {
        val u = find(edge.first)
        val v = find(edge.second)
        if (u != v) {
            y++
            union[u] = y
            union[v] = y
            children[y].add(u)
            children[y].add(v)
            amtNodes[y] = amtNodes[u] + amtNodes[v]
            amtEdges[y] = amtEdges[u] + amtEdges[v]
        }
        val w = find(edge.first)
        amtEdges[w]++
        if (amtEdges[w] == (amtNodes[w] * (amtNodes[w] - 1)) / 2) {
            candidates.add(w)
        }
    }
    var z = 0
    val l = IntArray(2 * n)
    val r = IntArray(2 * n)
    fun recur(a: Int) {
        l[a] = z + 1
        if (children[a].isEmpty()) {
            z++
        } else {
            for (b in children[a]) {
                recur(b)
            }
        }
        r[a] = z
        //println("l[$a] = ${l[a]}, r[$a] = ${r[a]}")
    }
    recur(y)
    val dp = Array(n + 1) { LongArray(n + 1) }
    dp[0][0] = 1L
    candidates.sortBy { r[it] }
    for (c in candidates) {
        //println(c)
        for (j in 1..n) {
            dp[r[c]][j] += dp[l[c] - 1][j - 1]
            dp[r[c]][j] %= MOD
        }
    }
    println(dp[n].toList().subList(1, n + 1).joinToString(" "))
}