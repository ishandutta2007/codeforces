import kotlin.math.abs
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(" ").map { it.toLong() }
        val answer = abs(a - b)
        if (answer == 0L) {
            println("0 0")
        } else {
            val m = min(a, b)
            println("$answer ${min(m % answer, (((-m) % answer) + answer) % answer)}")
        }
    }
}