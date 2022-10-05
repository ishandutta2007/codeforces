import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m, _) = jin.readLine().split(" ").map { it.toLong() }
        val freqs = jin.readLine().split(" ").map { it.toLong() }
        val answer = solve(n, m, freqs) || solve(m, n, freqs)
        out.appendln(if (answer) "Yes" else "No")
    }
    print(out)
}

fun solve(n: Long, m: Long, freqs: List<Long>): Boolean {
    val options = freqs.map { it / n }.filter { it >= 2L }.sortedDescending()
    var total = 0L
    var minimum = 0L
    for ((j, x) in options.withIndex()) {
        total += x
        minimum += 2L
        if (m in minimum..total) {
            return true
        }
    }
    return false
}