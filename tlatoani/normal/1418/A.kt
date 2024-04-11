import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (x, y, k) = jin.readLine().split(" ").map { it.toLong() }
        println((((k * (y + 1L)) - 1L + x - 2L) / (x - 1L)) + k)
    }
}