import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (a, b, c) = jin.readLine().split(" ").map { it.toLong() }
        val x = if (a < c) 1 else -1
        val y = if (c < a * b) b else -1L
        println("$x $y")
    }
}