import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val required = (listOf(0) + jin.readLine().split(" ").map { it.toInt() }).sorted()
        var answer = 0
        for (j in 0..n) {
            if (j >= required[j]) {
                answer = j + 1
            }
        }
        println(answer)
    }
}