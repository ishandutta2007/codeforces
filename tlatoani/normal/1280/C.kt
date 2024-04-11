import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val k = jin.readLine().toInt()
        val adj = Array((2 * k) + 1) { mutableMapOf<Int, Long>() }
        for (j in 2..2 * k) {
            val tokenizer = StringTokenizer(jin.readLine())
            val a = tokenizer.nextToken().toInt()
            val b = tokenizer.nextToken().toInt()
            val t = tokenizer.nextToken().toLong()
            adj[a][b] = t
            adj[b][a] = t
        }
        val parent = IntArray((2 * k) + 1)
        val subTreeSize = IntArray((2 * k) + 1) { 1 }
        val bfs = mutableListOf<Int>()
        bfs.add(1)
        for (j in 0 until 2 * k) {
            for ((child, t) in adj[bfs[j]]) {
                if (child != parent[bfs[j]]) {
                    parent[child] = bfs[j]
                    bfs.add(child)
                }
            }
        }
        var answer1 = 0L
        var answer2 = 0L
        for (j in bfs.reversed()) {
            subTreeSize[parent[j]] += subTreeSize[j]
            if (j != 1) {
                val t = adj[j][parent[j]]!!
                if (subTreeSize[j] % 2 == 1) {
                    answer1 += t
                }
                answer2 += min(subTreeSize[j], (2 * k) - subTreeSize[j]).toLong() * t
            }
        }
        println("$answer1 $answer2")
    }
}