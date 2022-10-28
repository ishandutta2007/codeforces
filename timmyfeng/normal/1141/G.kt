import java.io.*

lateinit var adj: Array<MutableList<Pair<Int, Int>>>
lateinit var ans: IntArray
var r = 0

fun dfs(u: Int, p: Int, x: Int) {
    var y = x
    for ((c, e) in adj[u]) {
        if (c != p) {
            y = (y + 1) % r
            dfs(c, u, y)
            ans[e] = y + 1
        }
    }
}

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val (n, k) = reader.readLine().split(" ").map { it.toInt() }
    adj = Array(n + 1) { mutableListOf() }

    for (i in 0 until n - 1) {
        val (u, v) = reader.readLine().split(" ").map { it.toInt() }
        adj[u].add(v to i)
        adj[v].add(u to i)
    }

    val deg = mutableListOf<Int>()
    for (i in 1..n) {
        deg.add(adj[i].size)
    }
    deg.sortDescending()

    r = deg[k]
    ans = IntArray(n - 1)
    dfs(1, 0, 0)

    writer.println(r)
    writer.println(ans.joinToString(" "))

    writer.close()
}