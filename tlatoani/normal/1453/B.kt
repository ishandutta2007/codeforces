import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toLong() }
        val initial = (1 until n).map { abs(ay[it] - ay[it - 1]) }.sum()
        var answer = initial
        answer = min(answer, initial - abs(ay[1] - ay[0]))
        answer = min(answer, initial - abs(ay[n - 1] - ay[n - 2]))
        for (j in 1..n - 2) {
            answer = min(answer, initial - abs(ay[j] - ay[j - 1]) - abs(ay[j + 1] - ay[j]) + abs(ay[j + 1] - ay[j - 1]))
        }
        println(answer)
    }
}