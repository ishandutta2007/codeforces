import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val adj = Array(n + 1) { mutableListOf<Edge>() }
    for (j in 1..m) {
        val (a, b, w) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(Edge(b, w))
        adj[b].add(Edge(a, w))
    }
    val dist = LongArray(n + 1) { Long.MAX_VALUE }
    dist[1] = 0L
    val distExtra = Array(51) { LongArray(n + 1) { Long.MAX_VALUE } }
    val pq = PriorityQueue<Node>(compareBy { it.dist })
    pq.add(Node(1, 0L))
    while (pq.isNotEmpty()) {
        val (a, d) = pq.remove()
        if (a <= n) {
            if (d == dist[a]) {
                for ((b, w) in adj[a]) {
                    if (adj[b].size <= 50) {
                        for ((c, x) in adj[b]) {
                            if (d + ((w + x) * (w + x)).toLong() < dist[c]) {
                                dist[c] = d + ((w + x) * (w + x)).toLong()
                                pq.add(Node(c, dist[c]))
                            }
                        }
                    } else {
                        if (d < distExtra[w][b]) {
                            distExtra[w][b] = d
                            pq.add(Node((w shl 20) + b, d))
                        }
                    }
                }
            }
        } else {
            val b = a and ((1 shl 20) - 1)
            val w = a shr 20
            if (d == distExtra[w][b]) {
                for ((c, x) in adj[b]) {
                    if (d + ((w + x) * (w + x)).toLong() < dist[c]) {
                        dist[c] = d + ((w + x) * (w + x)).toLong()
                        pq.add(Node(c, dist[c]))
                    }
                }
            }
        }
    }
    val joiner = StringJoiner(" ")
    for (a in 1..n) {
        joiner.add((if (dist[a] == Long.MAX_VALUE) -1L else dist[a]).toString())
    }
    println(joiner)
}

data class Edge(val to: Int, val weight: Int)
data class Node(val node: Int, val dist: Long)