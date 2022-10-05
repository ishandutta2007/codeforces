import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        jin.readLine()
        var answer = 0L
        for (a in jin.readLine().split(" ").map { it.toLong() }) {
            answer = max(0L, answer + a)
        }
        out.appendln(answer)
    }
    print(out)
}