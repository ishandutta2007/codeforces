import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val edges = Array(m) {
            val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
            Edge(a, b, c.toLong())
        }
        val dists = Array(n + 1) { LongArray(n + 1) { Int.MAX_VALUE.toLong() } }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (a in 1..n) {
            dists[a][a] = 0L
        }
        for ((a, b) in edges) {
            dists[a][b] = 1L
            dists[b][a] = 1L
        }
        for (b in 1..n) {
            for (a in 1..n) {
                for (c in 1..n) {
                    dists[a][c] = min(dists[a][c], dists[a][b] + dists[b][c])
                }
            }
        }
        var answer = Long.MAX_VALUE
        for ((a, b, w) in edges) {
            var here = Long.MAX_VALUE
            here = min(here, dists[1][a] + 1L + dists[b][n])
            here = min(here, dists[1][b] + 1L + dists[a][n])
            for (c in 1..n) {
                here = min(here, dists[a][c] + 2L + dists[c][1] + dists[c][n])
                here = min(here, dists[b][c] + 2L + dists[c][1] + dists[c][n])
            }
            answer = min(answer, here * w)
        }
        println(answer)
    }
}

data class Edge(val from: Int, val to: Int, val weight: Long)