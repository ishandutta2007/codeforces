import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val x = line[1].toLong()
    var months = jin.readLine().split(" ").map { it.toLong() }
    months += months
    var r = 0
    var currDays = 0L
    var currHugs = 0L
    var answer = 0L
    for (l in 0 until n) {
        while (currDays <= x) {
            currDays += months[r]
            currHugs += (months[r] * (months[r] + 1L)) / 2L
            r++
        }
        if (currDays - months[l] <= x) {
            val limit = currDays - x
            answer = max(answer, currHugs - ((limit * (limit + 1L)) / 2L))
        }
        currDays -= months[l]
        currHugs -= (months[l] * (months[l] + 1)) / 2L
    }
    println(answer)
}