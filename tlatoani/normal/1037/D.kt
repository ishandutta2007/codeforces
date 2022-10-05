import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(b)
        adj[b].add(a)
    }
    val sequence = jin.readLine().split(" ").map { it.toInt() }
    if (sequence[0] == 1) {
        var j = 1
        val q = LinkedList<Int>()
        q.add(1)
        while (q.isNotEmpty()) {
            val a = q.remove()
            while (j < n && sequence[j] in adj[a]) {
                adj[a].remove(sequence[j])
                adj[sequence[j]].remove(a)
                q.add(sequence[j])
                j++
            }
            if (adj[a].isNotEmpty()) {
                println("nO")
                return
            }
        }
        println("yEs")
    } else {
        println("nO")
    }
}