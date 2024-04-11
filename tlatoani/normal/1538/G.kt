import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (x, y, a, b) = readLine()!!.split(" ").map { it.toLong() }
        if (a == b) {
            println(min(x, y) / b)
        } else {
            var answer = 0L
            fun check(d: Long) {
                if (d in 0L..1000000000L && a * d <= x && b * d <= y) {
                    answer = max(answer, d + min((x - (a * d)) / b, (y - (b * d)) / a))
                }
            }
            check(0L)
            check(min(x / a, y / b))
            check(((b * y) - (a * x)) / ((b * b) - (a * a)))
            check((((b * y) - (a * x)) / ((b * b) - (a * a))) + 1L)
            println(answer)
        }
    }
}