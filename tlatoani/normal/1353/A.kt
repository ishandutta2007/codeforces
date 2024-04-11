import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val m = line[1].toInt()
        if (n == 1) {
            println(0)
        } else if (n == 2) {
            println(m)
        } else {
            println(2 * m)
        }
    }
}