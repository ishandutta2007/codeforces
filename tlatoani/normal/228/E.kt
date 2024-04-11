import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.system.exitProcess

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val adj = Array(2) { Array(n + 1) { mutableListOf<Int>() } }
    for (j in 1..m) {
        val (a, b, c) = jin.readLine().split(" ").map { it.toInt() }
        adj[1 - c][a].add(b)
        adj[1 - c][b].add(a)
    }
    val seen = IntArray(n + 1)
    val answer = mutableListOf<Int>()
    for (r in 1..n) {
        if (seen[r] == 0) {
            seen[r] = 1
            fun recur(a: Int) {
                if (seen[a] == -1) {
                    answer.add(a)
                }
                for (b in adj[0][a]) {
                    if (seen[b] == 0) {
                        seen[b] = seen[a]
                        recur(b)
                    } else if (seen[b] != seen[a]) {
                        println("Impossible")
                        exitProcess(0)
                    }
                }
                for (b in adj[1][a]) {
                    if (seen[b] == 0) {
                        seen[b] = -seen[a]
                        recur(b)
                    } else if (seen[b] == seen[a]) {
                        println("Impossible")
                        exitProcess(0)
                    }
                }
            }
            recur(r)
        }
    }
    println(answer.size)
    println(answer.joinToString(" "))
}