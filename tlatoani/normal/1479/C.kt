import kotlin.math.max

fun main() {
    var (l, r) = readLine()!!.split(" ").map { it.toInt() }
    if (r == 1) {
        println("YES")
        println("2 1")
        println("1 2 1")
        return
    }
    val lIs1 = l == 1
    l = max(2, l)
    var k = 0
    while (r - l + 1 >= 1 shl k) {
        k++
    }
    val edges = mutableListOf<Edge>()
    val n = k + 2
    for (v in 2..k + 1) {
        edges.add(Edge(1, v, 1))
    }
    if (lIs1) {
        edges.add(Edge(1, n, 1))
    }
    for (u in 2..k + 1) {
        for (v in u + 1..k + 1) {
            edges.add(Edge(u, v, 1 shl (u - 2)))
        }
        if ((r - l + 1) shr (u - 2) and 1 == 1) {
            edges.add(Edge(u, n, l - 1 + (((r - l + 1) shr (u - 1)) shl (u - 1))))
        }
    }
    println("YES")
    println("$n ${edges.size}")
    for ((from, to, length) in edges) {
        println("$from $to $length")
    }
}

data class Edge(val from: Int, val to: Int, val length: Int)