import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (b, g, k) = jin.readLine().split(" ").map { it.toInt() }
        val adj = Array(g + 1) { mutableListOf<Int>() }
        val boyTokenizer = StringTokenizer(jin.readLine())
        val girlTokenizer = StringTokenizer(jin.readLine())
        for (j in 1..k) {
            adj[girlTokenizer.nextToken().toInt()].add(boyTokenizer.nextToken().toInt())
        }
        var answer = 0L
        var prev = 0L
        val specific = LongArray(b + 1)
        for (girl in 1..g) {
            for (boy in adj[girl]) {
                answer += prev - specific[boy]
            }
            for (boy in adj[girl]) {
                prev++
                specific[boy]++
            }
        }
        out.appendln(answer)
    }
    print(out)
}