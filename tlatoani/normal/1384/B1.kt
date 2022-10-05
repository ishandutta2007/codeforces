import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k, l) = jin.readLine().split(" ").map { it.toInt() }
        val depths = jin.readLine().split(" ").map { it.toInt() }
        var curr = k
        var answer = true
        for (d in depths) {
            if (d > l) {
                answer = false
                break
            }
            if (d + k <= l) {
                curr = k
            } else if (curr > 0) {
                curr = min(curr - 1, l - d)
            } else {
                if (abs(curr) + 1 + d > l) {
                    answer = false
                    break
                }
                curr--
            }
        }
        out.appendln(if (answer) "yEs" else "nO")
    }
    print(out)
}