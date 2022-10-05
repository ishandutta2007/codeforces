import kotlin.math.max
import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, x, y) = readLine()!!.split(" ").map { it.toInt() }
        val a = min(x, y)
        val b = max(x, y)
        var answer = Int.MAX_VALUE
        for (c in a until b) {
            answer = min(answer, max(min(a - 1, c - a) + (c - 1), min(b - (c + 1), n - b) + (n - (c + 1))))
        }
        println(answer)
    }
}