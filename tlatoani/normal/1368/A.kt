import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var (a, b, n) = jin.readLine().split(" ").map { it.toLong() }
        var answer = 0
        while (max(a, b) <= n) {
            answer++
            if (a > b) {
                b += a
            } else {
                a += b
            }
        }
        println(answer)
    }
}