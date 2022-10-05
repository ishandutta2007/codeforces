import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        val tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val answer = mutableListOf<Pair<Int, Int>>()
    fun recur(a: Int, t: Int) {
        answer.add(Pair(a, t))
        for (b in adj[a]) {
            adj[b].remove(a)
        }
        if (adj[a].size < t) {
            var u = t - adj[a].size - 1
            answer.add(Pair(a, u))
            for (b in adj[a]) {
                u++
                recur(b, u)
                answer.add(Pair(a, u))
            }
        } else {
            var u = t
            for (b in adj[a]) {
                u++
                recur(b, u)
                answer.add(Pair(a, u))
                if (u == adj[a].size + 1) {
                    u = 0
                    answer.add(Pair(a, u))
                }
            }
        }
    }
    answer.add(Pair(1, 0))
    var t = 0
    for (b in adj[1]) {
        adj[b].remove(1)
        t++
        recur(b, t)
        answer.add(Pair(1, t))
    }
    val out = StringBuilder()
    out.appendln(answer.size)
    for (p in answer) {
        out.append(p.first).append(' ').appendln(p.second)
    }
    print(out)
}