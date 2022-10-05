import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        println(jin.readLine().split(" ").map { it.toLong() }.sum() - 1L)
    }
}