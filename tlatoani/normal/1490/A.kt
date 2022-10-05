import kotlin.math.max
import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        var answer = 0
        for (j in 1 until n) {
            var a = max(ay[j - 1], ay[j])
            var b = min(ay[j - 1], ay[j])
            while (2 * b < a) {
                answer++
                b *= 2
            }
        }
        println(answer)
    }
}