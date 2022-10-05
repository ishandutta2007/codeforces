import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, x) = jin.readLine().split(" ").map { it.toInt() }
        var degree = 0
        for (j in 2..n) {
            if (x in jin.readLine().split(" ").map { it.toInt() }) {
                degree++
            }
        }
        if (degree <= 1 || (n - 1) % 2 == 1) {
            println("Ayush")
        } else {
            println("Ashish")
        }
    }
}