import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val paths = Array(n) { LinkedList(jin.readLine().split(" ").map { it.toInt() }.sorted()) }
        val answer = Array(n) { IntArray(m) }
        for (j in 0 until m) {
            var minimo = 1000000000
            for (k in 0 until n) {
                minimo = min(minimo, paths[k][0])
            }
            var found = false
            for (k in 0 until n) {
                if (!found && paths[k].first == minimo) {
                    answer[k][j] = paths[k].removeFirst()
                    found = true
                } else {
                    answer[k][j] = paths[k].removeLast()
                }
            }
        }
        answer.forEach { out.appendln(it.joinToString(" ")) }
    }
    print(out)
}