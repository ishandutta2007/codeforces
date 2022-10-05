import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val coords = jin.readLine().split(" ").map { it.toLong() }
        println(((coords[2] - coords[0]) * (coords[3] - coords[1])) + 1L)
    }
}