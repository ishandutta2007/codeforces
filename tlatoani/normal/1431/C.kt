import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val prices = jin.readLine().split(" ").map { it.toLong() }.sortedDescending()
        var answer = 0L
        for (j1 in 1..n / k) {
            var pos = 0L
            for (j2 in j1 * (k - 1) until j1 * k) {
                pos += prices[j2]
            }
            answer = max(answer, pos)
        }
        println(answer)
    }
}