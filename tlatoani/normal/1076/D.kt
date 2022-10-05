import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, k) = jin.readLine().split(" ").map { it.toInt() }
    if (k == 0) {
        println(0)
        println()
        return
    }
    val adj = Array(n + 1) { mutableListOf<Edge>() }
    for (j in 1..m) {
        val (x, y, w) = jin.readLine().split(" ").map { it.toInt() }
        adj[x].add(Edge(y, w.toLong(), j))
        adj[y].add(Edge(x, w.toLong(), j))
    }
    val dists = LongArray(n + 1) { Long.MAX_VALUE }
    dists[1] = 0L
    val lastEdge = IntArray(n + 1)
    val pq = PriorityQueue<Node>(compareBy { it.dist })
    pq.add(Node(1, 0L))
    val e = min(n - 1, k)
    val answer = mutableListOf<Int>()
    while (pq.isNotEmpty()) {
        val (x, d) = pq.remove()
        if (d == dists[x]) {
            if (lastEdge[x] != 0) {
                answer.add(lastEdge[x])
                if (answer.size == e) {
                    println(e)
                    println(answer.joinToString(" "))
                    return
                }
            }
            for ((y, w, j) in adj[x]) {
                if (d + w < dists[y]) {
                    dists[y] = d + w
                    lastEdge[y] = j
                    pq.add(Node(y, dists[y]))
                }
            }
        }
    }
}

data class Edge(val to: Int, val weight: Long, val index: Int)
data class Node(val index: Int, val dist: Long)