import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, a, b, da, db) = jin.readLine().split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 2..n) {
            val (x, y) = jin.readLine().split(" ").map { it.toInt() }
            adj[x].add(y)
            adj[y].add(x)
        }
        if (2 * da >= db) {
            out.appendln("Alice")
        } else {
            val dist = IntArray(n + 1) { -1 }
            dist[a] = 0
            fun recur1(x: Int) {
                for (y in adj[x]) {
                    if (dist[y] == -1) {
                        dist[y] = dist[x] + 1
                        recur1(y)
                    }
                }
            }
            recur1(a)
            if (dist[b] <= da) {
                out.appendln("Alice")
            } else {
                val g = (1..n).maxBy { dist[it] }!!
                dist.fill(-1)
                dist[g] = 0
                fun recur2(x: Int) {
                    for (y in adj[x]) {
                        if (dist[y] == -1) {
                            dist[y] = dist[x] + 1
                            recur1(y)
                        }
                    }
                }
                recur2(g)
                out.appendln(if (2 * da >= dist.max()!!) "Alice" else "Bob")
            }
        }
    }
    print(out)
}