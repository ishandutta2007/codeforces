import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, x, y) = jin.readLine().split(" ").map { it.toInt() }
    if (x > y) {
        println(n)
    } else {
        println((jin.readLine().split(" ").count() { it.toInt() <= x } + 1) / 2)
    }
}