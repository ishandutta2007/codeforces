import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        var ay = jin.readLine().split(" ").map { it.toInt() }.sorted()
        val answer = (1 until n).all { abs(ay[it - 1] - ay[it]) <= 1 }
        out.appendln(if (answer) "YES" else "NO")
    }
    print(out)
}