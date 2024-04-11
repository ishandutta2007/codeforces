import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Edge>() }
        for (j in 0 until m) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(Edge(j, a, b))
            adj[b].add(Edge(j, b, a))
        }
        out.appendln((1..n).count { adj[it].size % 2 == 0 })
        for (a in 1..n) {
            if (adj[a].size % 2 == 1) {
                for (edge in adj[a]) {
                    if (adj[edge.to].size % 2 == 1) {
                        if (a < edge.to) {
                            out.append(a).append(' ').appendln(edge.to)
                        }
                    } else {
                        adj[0].add(edge)
                    }
                }
            }
        }
        val used = BooleanArray(m)
        fun recur(a: Int) {
            val a = if (adj[a].size % 2 == 1) 0 else a
            for (edge in adj[a]) {
                if (!used[edge.ix]) {
                    used[edge.ix] = true
                    out.append(edge.from).append(' ').appendln(edge.to)
                    recur(edge.to)
                }
            }
        }
        for (a in 0..n) {
            recur(a)
        }
    }
    print(out)
}

data class Edge(val ix: Int, val from: Int, val to: Int)