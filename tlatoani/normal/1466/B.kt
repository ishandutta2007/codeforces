import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val xs = jin.readLine().split(" ").map { it.toInt() }
        var prev = 0
        var answer = 0
        for (x in xs) {
            if (prev <= x) {
                answer++
                if (prev == x) {
                    prev++
                } else {
                    prev = x
                }
            }
        }
        println(answer)
    }
}