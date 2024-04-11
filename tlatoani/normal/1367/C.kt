import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val restaurant = "1" + "0".repeat(k) + jin.readLine() + "0".repeat(k) + "1"
        var answer = 0
        var curr = 0
        for (table in restaurant) {
            if (table == '0') {
                curr++
            } else {
                //println("curr = $curr")
                answer += max(0, (curr - k) / (k + 1))
                curr = 0
            }
        }
        out.appendln(answer)
    }
    print(out)
}