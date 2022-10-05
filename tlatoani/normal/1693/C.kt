import java.util.*

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val rev = Array(n + 1) { mutableListOf<Int>() }
    val remDegrees = IntArray(n + 1)
    repeat(m) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        rev[b].add(a)
        remDegrees[a]++
    }
    val dists = IntArray(n + 1) { m }
    dists[n] = 0
    val pq = PriorityQueue<Node>(compareBy { it.dist })
    pq.add(Node(n, 0))
    while (pq.isNotEmpty()) {
        val (a, d) = pq.remove()
        if (d == dists[a]) {
            for (b in rev[a]) {
                remDegrees[b]--
                val nd = d + remDegrees[b] + 1
                if (nd < dists[b]) {
                    dists[b] = nd
                    pq.add(Node(b, nd))
                }
            }
        }
    }
    println(dists[1])
}

data class Node(val node: Int, val dist: Int)