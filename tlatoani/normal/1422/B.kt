import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val matrix = Array(n) { jin.readLine().split(" ").map { it.toLong() } }
        val groups = mutableMapOf<Pair<Int, Int>, MutableList<Long>>()
        for (y in 1..n) {
            for (x in 1..m) {
                val w = min(y, n + 1 - y)
                val z = min(x, m + 1 - x)
                if (w == y && z == x) {
                    groups[Pair(w, z)] = mutableListOf()
                }
                groups[Pair(w, z)]!!.add(matrix[y - 1][x - 1])
            }
        }
        var answer = 0L
        for (list in groups.values) {
            list.sort()
            val median = list[list.size / 2]
            for (v in list) {
                answer += abs(v - median)
            }
        }
        println(answer)
    }
}