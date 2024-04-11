import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val union = IntArray(n + 1) { it }
    fun findUnion(u: Int): Int {
        if (union[union[u]] != union[u]) {
            union[u] = findUnion(union[u])
        }
        return union[u]
    }
    val edges = Array(m) {
        val (a, b, weight) = jin.readLine().split(" ").map { it.toInt() }
        Edge(a, b, weight)
    }
    edges.sortBy { it.weight }
    var j = 0
    var answer = 0
    while (j < m) {
        var k = j
        while (k < m && edges[k].weight == edges[j].weight) {
            if (findUnion(edges[k].a) == findUnion(edges[k].b)) {
                answer--
            }
            k++
        }
        k = j
        while (k < m && edges[k].weight == edges[j].weight) {
            if (findUnion(edges[k].a) == findUnion(edges[k].b)) {
                answer++
            } else {
                union[findUnion(edges[k].a)] = findUnion(edges[k].b)
            }
            k++
        }
        j = k
    }
    println(answer)
}

data class Edge(val a: Int, val b: Int, val weight: Int)