import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ").map { it.toInt() }
        val n = line[0]
        val m = line[1]
        val answer = LongArray(n + 1)
        val edges = Array(m) {
            val line = jin.readLine().split(" ")
            val res = Edge(line[0].toInt(), line[1].toInt(), line[2].toLong())
            answer[res.a] = max(answer[res.a], res.coins)
            answer[res.b] = max(answer[res.b], res.coins)
            res
        }
        var possible = true
        for (edge in edges) {
            if (min(answer[edge.a], answer[edge.b]) != edge.coins) {
                possible = false
                break
            }
        }
        if (possible) {
            out.appendln("YES")
            out.appendln(answer.joinToString(" ").substring(2))
        } else {
            out.appendln("NO")
        }
    }
    print(out)
}

data class Edge(val a: Int, val b: Int, val coins: Long)