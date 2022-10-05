import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (m, n) = jin.readLine().split(" ").map { it.toInt() }
    val ay = jin.readLine().split(" ").map { it.toLong() }
    val by = listOf(0L) + jin.readLine().split(" ").map { it.toLong() }
    val sets = Array(m) {
        val l = jin.readLine().split(" ").map { it.toInt() }
        l.subList(1, l.size)
    }
    var answer = 0L
    val edges = mutableListOf<Edge>()
    for (j in 0 until m) {
        for (k in sets[j]) {
            answer += ay[j] + by[k]
            edges.add(Edge(j + 1, k + m, ay[j] + by[k]))
        }
    }
    val union = IntArray(n + m + 1) { it }
    val rank = IntArray(n + m + 1) { 1 }
    fun find(u: Int): Int {
        if (union[u] != union[union[u]]) {
            union[u] = find(union[u])
        }
        return union[u]
    }
    fun join(u: Int, v: Int) {
        if (rank[u] > rank[v]) {
            rank[u] += rank[v]
            union[v] = u
        } else {
            rank[v] += rank[u]
            union[u] = v
        }
    }
    edges.sortByDescending { it.cost }
    for ((a, b, c) in edges) {
        val u = find(a)
        val v = find(b)
        if (u != v) {
            join(u, v)
            answer -= c
        }
    }
    println(answer)
}

data class Edge(val from: Int, val to: Int, val cost: Long)