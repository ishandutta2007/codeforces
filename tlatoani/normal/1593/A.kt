import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        val x = max(0, max(b, c) + 1 - a)
        val y = max(0, max(a, c) + 1 - b)
        val z = max(0, max(a, b) + 1 - c)
        println("$x $y $z")
    }
}