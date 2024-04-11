import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 2..n) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        if (k == 1) {
            out.appendln(n - 1)
            continue
        }
        val amt = IntArray(n + 1) { adj[it].size }
        var answer = 0
        val q = LinkedList<Int>()
        val seen = BooleanArray(n + 1)
        for (a in 1..n) {
            if (adj[a].size == 1) {
                q.add(a)
            }
        }
        while (q.isNotEmpty()) {
            val a = q.remove()
            seen[a] = true
            for (b in adj[a]) {
                if (!seen[b]) {
                    amt[b]--
                    if (amt[b] % k == adj[b].size % k) {
                        answer++
                        if (amt[b] == 1) {
                            q.add(b)
                        }
                    }
                }
            }
        }
        out.appendln(answer)
    }
    print(out)
}