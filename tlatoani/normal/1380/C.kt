import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, x) = jin.readLine().split(" ").map { it.toLong() }
        val skills = jin.readLine().split(" ").map { it.toLong() }.sortedDescending()
        var answer = 0
        var curr = 0L
        for (skill in skills) {
            curr++
            if (skill * curr >= x) {
                answer++
                curr = 0L
            }
        }
        println(answer)
    }
}