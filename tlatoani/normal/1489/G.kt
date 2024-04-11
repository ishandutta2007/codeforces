import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val minNumber = (listOf(0L) + jin.readLine().split(" ").map { it.toLong() }).toLongArray()
    val edges = Array(m) {
        val (x, y, w) = jin.readLine().split(" ").map { it.toLong() }
        Edge(x.toInt(), y.toInt(), w)
    }
    edges.sortBy { it.cost }
    val union = IntArray(n + 1) { it }
    fun find(u: Int): Int {
        if (union[union[u]] != union[u]) {
            union[u] = find(union[u])
        }
        return union[u]
    }
    val components = TreeSet<Int>(compareBy({ minNumber[it] }, { it }))
    fun merge(u: Int, v: Int) {
        components.remove(u)
        components.remove(v)
        minNumber[v] = min(minNumber[u], minNumber[v])
        union[u] = v
        components.add(v)
    }
    var answer = 0L
    components.addAll(1..n)
    var edgeIndex = 0
    while (components.size != 1) {
        if (edgeIndex != m) {
            val (x, y) = edges[edgeIndex]
            if (find(x) == find(y)) {
                edgeIndex++
                continue
            }
        }
        val u = components.first()
        val v = components.higher(u)!!
        if (edgeIndex == m || (minNumber[u] + minNumber[v] < edges[edgeIndex].cost)) {
            answer += minNumber[u]
            answer += minNumber[v]
            merge(u, v)
        } else {
            val (x, y, cost) = edges[edgeIndex]
            answer += cost
            merge(find(x), find(y))
            edgeIndex++
        }
    }
    println(answer)
}

data class Edge(val x: Int, val y: Int, val cost: Long)