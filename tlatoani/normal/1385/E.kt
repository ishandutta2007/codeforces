import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        val edges = mutableListOf<Pair<Int, Int>>()
        for (j in 1..m) {
            val (t, a, b) = jin.readLine().split(" ").map { it.toInt() }
            when (t) {
                0 -> edges.add(Pair(a, b))
                1 -> adj[a].add(b)
            }
        }
        val seen = BooleanArray(n + 1)
        val curr = BooleanArray(n + 1)
        val order = IntArray(n + 1)
        var k = 0
        var works = true
        fun recur(a: Int) {
            if (curr[a]) {
                works = false
                return
            }
            if (!seen[a]) {
                seen[a] = true
                curr[a] = true
                for (b in adj[a]) {
                    recur(b)
                }
                curr[a] = false
                k++
                order[a] = k
            }
        }
        for (r in 1..n) {
            recur(r)
        }
        if (works) {
            out.appendln("YES")
            for ((a, b) in edges) {
                if (order[a] > order[b]) {
                    out.appendln("$a $b")
                } else {
                    out.appendln("$b $a")
                }
            }
            for (a in 1..n) {
                for (b in adj[a]) {
                    out.appendln("$a $b")
                }
            }
        } else {
            out.appendln("NO")
        }
    }
    print(out)
}