import java.util.*
import kotlin.math.max

fun main() {
    val s = readLine()!!
    val times = Array(2) { IntArray(s.length + 1) { s.length + 1 } }
    val amts = Array(2) { IntArray(s.length + 1) }
    times.forEach { it[0] = 0 }
    var amt0 = 0
    var amt1 = 0
    for (j in 1..s.length) {
        when (s[j - 1]) {
            '0' -> {
                amt0++
                times[0][amt0] = j
            }
            '1' -> {
                amt1++
                times[1][amt1] = j
            }
        }
        amts[0][j] = amt0
        amts[1][j] = amt1
    }
    val joiner = StringJoiner(" ")
    for (k in 1..s.length) {
        var answer = 1
        var curr0 = 0
        var curr1 = 0
        while (amt0 - curr0 > k && amt1 - curr1 > k) {
            answer++
            val j = max(times[0][curr0 + k + 1], times[1][curr1 + k + 1]) - 1
            curr0 = amts[0][j]
            curr1 = amts[1][j]
        }
        joiner.add(answer.toString())
    }
    println(joiner)
}