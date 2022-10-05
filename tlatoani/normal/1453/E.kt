import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 2..n) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        var answer = 0
        fun recur(a: Int, parent: Int): Int {
            val things = mutableListOf<Int>()
            for (b in adj[a]) {
                if (b != parent) {
                    things.add(recur(b, a))
                }
            }
            things.sortDescending()
            if (a == 1) {
                if (things.size >= 2) {
                    answer = max(answer, things[1] + 1)
                }
                answer = max(answer, things[0])
                return 0
            } else if (things.isNotEmpty()) {
                answer = max(answer, things[0] + 1)
                return things.last() + 1
            } else {
                return 1
            }
        }
        recur(1, 0)
        println(answer)
    }
}