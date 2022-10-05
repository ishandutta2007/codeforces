import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.exp

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    val x = line[2].toLong()
    val asphalt = (listOf(0L) + jin.readLine().split(" ").map { it.toLong() }).toLongArray()
    if (asphalt.sum() < (n - 1).toLong() * x) {
        println("NO")
    } else {
        val out = StringBuilder()
        out.appendln("YES")
        val adj = Array(n + 1) { LinkedList<Edge>() }
        for (j in 1..m) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(Edge(b, j))
            adj[b].add(Edge(a, j))
        }
        val union = IntArray(n + 1) { it }
        fun find(u: Int): Int {
            if (union[union[u]] != union[u]) {
                union[u] = find(union[u])
            }
            return union[u]
        }
        fun merge(u: Int, v: Int) {
            asphalt[u] = asphalt[u] + asphalt[v] - x
            adj[u].addAll(adj[v])
            union[v] = u
        }
        val disp = Stack<Int>()
        disp.addAll((1..n).filter { asphalt[it] >= x })
        var neces = n - 1
        while (disp.isNotEmpty()) {
            val u = disp.pop()
            if (u == find(u) && asphalt[u] >= x && neces > 0) {
                while (find(adj[u].first.to) == u) {
                    adj[u].removeFirst()
                }
                val (b, j) = adj[u].removeFirst()
                out.append(j).append(' ')
                val v = find(b)
                if (adj[u].size > adj[v].size) {
                    merge(u, v)
                } else {
                    merge(v, u)
                }
                if (asphalt[find(u)] >= x) {
                    disp.push(find(u))
                }
                neces--
            }
        }
        val wasComponent = BooleanArray(n + 1) { find(it) == it }
        for (a in 1..n) {
            if (wasComponent[a]) {
                val u = find(a)
                for ((b, j) in adj[a]) {
                    val v = find(b)
                    if (v != u) {
                        out.append(j).append(' ')
                        union[v] = u
                    }
                }
            }
        }
        print(out)
    }
}

data class Edge(val to: Int, val ix: Int)