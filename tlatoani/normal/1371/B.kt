import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, r) = jin.readLine().split(" ").map { it.toLong() }
        println(if (n > r) ((r * (r + 1L)) / 2L) else (((n * (n - 1L)) / 2L) + 1L))
    }
}