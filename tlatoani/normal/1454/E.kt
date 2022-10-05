import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 1..n) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        val union = IntArray(n + 1) { it }
        val seenEdge = mutableSetOf<Pair<Int, Int>>()
        fun find(u: Int): Int {
            if (union[union[u]] != union[u]) {
                union[u] = find(union[u])
            }
            return union[u]
        }
        var s = 0
        var t = 0
        nodeLoop@for (a in 1..n) {
            for (b in adj[a]) {
                val x = min(a, b)
                val y = max(a, b)
                if (Pair(x, y) !in seenEdge) {
                    seenEdge.add(Pair(x, y))
                    val u = find(x)
                    val v = find(y)
                    if (u == v) {
                        s = x
                        t = y
                        break@nodeLoop
                    } else {
                        union[u] = v
                    }
                }
            }
        }
        val seen = BooleanArray(n + 1)
        val prev = IntArray(n + 1)
        val q = LinkedList<Int>()
        seen[t] = true
        q.add(t)
        while (q.isNotEmpty()) {
            val a = q.remove()
            for (b in adj[a]) {
                if ((a != t || b != s) && !seen[b]) {
                    seen[b] = true
                    prev[b] = a
                    q.add(b)
                }
            }
        }
        val path = mutableListOf<Int>()
        var a = s
        while (a != 0) {
            path.add(a)
            a = prev[a]
        }
        seen.fill(false)
        var answer = n.toLong() * (n - 1).toLong()
        for (a in path) {
            seen[a] = true
        }
        for (r in path) {
            var amt = 0L
            fun recur(a: Int) {
                amt++
                for (b in adj[a]) {
                    if (!seen[b]) {
                        seen[b] = true
                        recur(b)
                    }
                }
            }
            recur(r)
            answer -= (amt * (amt - 1L)) / 2L
        }
        out.appendln(answer)
    }
    print(out)
}