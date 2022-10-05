import kotlin.math.max
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val sequence = readLine()!!.split(" ").map { it.toLong() }
    var answer = 0L
    for (j in 0 until n step 2) {
        var total = 0L
        var minimum = sequence[j]
        for (k in j + 1 until n step 2) {
            total += sequence[k - 1] - sequence[k]
            val lowerBound = max(0L, total)
            val upperBound = minOf(sequence[j], sequence[k] + total, minimum)
            if (lowerBound <= upperBound) {
                answer += upperBound - lowerBound + 1L
            }
            minimum = min(minimum, total)
        }
    }
    println(answer - (n / 2).toLong())
}