import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(n + 1) { mutableListOf<Pair<Int, Long>>() }
    for (j in 2..n) {
        val (a, b, w) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(Pair(b, w.toLong()))
        adj[b].add(Pair(a, w.toLong()))
    }
    var answer = 0L
    var m = 0L
    val seen = BooleanArray(n + 1)
    fun recur(a: Int, d: Long) {
        if (!seen[a]) {
            seen[a] = true
            m = max(m, d)
            for ((b, w) in adj[a]) {
                answer += w
                recur(b, d + w)
            }
        }
    }
    recur(1, 0L)
    println(answer - m)
}