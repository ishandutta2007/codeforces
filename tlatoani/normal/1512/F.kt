import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val c = jin.readLine().substringAfter(' ').toLong()
        val ay = jin.readLine().split(" ").map { it.toLong() }
        val by = jin.readLine().split(" ").map { it.toLong() }
        var answer = Long.MAX_VALUE
        var balance = 0L
        var days = 0L
        for (j in ay.indices) {
            answer = min(answer, days + ((max(0L, c - balance) + ay[j] - 1L) / ay[j]))
            if (j < by.size) {
                val daysToPromote = (max(0L, by[j] - balance) + ay[j] - 1L) / ay[j]
                days += daysToPromote + 1L
                balance += daysToPromote * ay[j]
                balance -= by[j]
            }
        }
        out.appendln(answer)
    }
    print(out)
}