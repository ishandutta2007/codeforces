import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val k = (jin.readLine().toLong() - 1L) / 2L
        println((8L * k * (k + 1L) * ((2L * k) + 1L)) / 6L)
    }
}