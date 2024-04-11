import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var line = jin.readLine()
    var six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val m = line.substring(six + 1).toInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        line = jin.readLine()
        six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        adj[b].add(a)
    }
    val k = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val path = IntArray(k) { tokenizer.nextToken().toInt() }
    val t = path.last()
    val dist = IntArray(n + 1) { Int.MAX_VALUE }
    val prev = Array(n + 1) { mutableSetOf<Int>() }
    dist[t] = 0
    val q = LinkedList<Int>()
    q.add(t)
    while (q.isNotEmpty()) {
        val a = q.remove()
        for (b in adj[a]) {
            if (dist[a] + 1 < dist[b]) {
                dist[b] = dist[a] + 1
                q.add(b)
            }
            if (dist[a] + 1 == dist[b]) {
                prev[b].add(a)
            }
        }
    }
    var mexico = 0
    var minimo = 0
    for (j in 0..path.size - 2) {
        if (prev[path[j]].contains(path[j + 1])) {
            if (prev[path[j]].size > 1) {
                mexico++
            }
        } else {
            mexico++
            minimo++
        }
    }
    println("$minimo $mexico")
}