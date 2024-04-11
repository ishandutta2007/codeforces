import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val p = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
        while (n > 0 && p[n] == n) {
            n--
        }
        var answer = if (n == 0) .0 else 1.0
        for (j in 1..m) {
            val line = jin.readLine().split(" ")
            val r = line[0].toInt()
            val p = line[1].toDouble()
            if (r >= n) {
                answer *= 1.0 - p
            }
        }
        println(1.0 - answer)
    }
}