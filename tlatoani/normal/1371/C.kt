import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (a, b, n, m) = jin.readLine().split(" ").map { it.toLong() }
        println(if (m <= min(a, b) && n + m <= a + b) "yEs" else "nO")
    }
}