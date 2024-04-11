import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        val dist = IntArray(n + 1) { -1 }
        val pq = PriorityQueue<Int>(compareBy { dist[it] })
        val degree = IntArray(n + 1) { adj[it].size }
        for (a in 1..n) {
            if (degree[a] <= 1) {
                dist[a] = 0
                pq.add(a)
            }
        }
        while (pq.isNotEmpty()) {
            val a = pq.remove()
            for (b in adj[a]) {
                degree[b]--
                if (degree[b] == 1) {
                    dist[b] = dist[a] + 1
                    pq.add(b)
                }
            }
        }
        println((1..n).count { dist[it] >= k })
    }
}