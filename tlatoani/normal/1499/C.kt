import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val segments = listOf(0L) + jin.readLine().split(" ").map { it.toLong() }
        var sumOdd = segments[1]
        var sumEven = 0L
        var minOdd = segments[1]
        var minEven = Long.MAX_VALUE
        var answer = Long.MAX_VALUE
        for (k in 2..n) {
            if (k % 2 == 1) {
                sumOdd += segments[k]
                minOdd = min(minOdd, segments[k])
            } else {
                sumEven += segments[k]
                minEven = min(minEven, segments[k])
            }
            answer = min(answer, sumOdd + ((n - ((k + 1) / 2)).toLong() * minOdd) + sumEven + ((n - (k / 2)).toLong() * minEven))
        }
        println(answer)
    }
}