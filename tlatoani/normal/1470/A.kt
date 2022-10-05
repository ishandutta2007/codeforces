import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val friends = jin.readLine().split(" ").map { it.toInt() - 1 }.sortedDescending()
        val presents = jin.readLine().split(" ").map { it.toLong() }
        var answer = 0L
        for (j in 0 until n) {
            answer += presents[min(j, friends[j])]
        }
        out.appendln(answer)
    }
    print(out)
}