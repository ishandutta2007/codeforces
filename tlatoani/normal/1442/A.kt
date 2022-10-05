import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toInt() }.toIntArray()
        var delta = ay[0]
        ay[0] = 0
        var answer = true
        for (j in 1 until n) {
            if (ay[j] < ay[j - 1]) {
                answer = false
                break
            }
            delta = min(delta, ay[j] - ay[j - 1])
            ay[j] -= delta
        }
        out.appendln(if (answer) "YES" else "NO")
    }
    print(out)
}