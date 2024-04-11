import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        println(if (jin.readLine().split(" ").map { it.toInt() }.toSet().size == n) "nO" else "yEs")
    }
}