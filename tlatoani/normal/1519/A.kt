import kotlin.math.max
import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (r, b, d) = readLine()!!.split(" ").map { it.toLong() }
        val x = min(r, b)
        val y = max(r, b)
        println(if (x * (d + 1L) >= y) "yEs" else "nO")
    }
}