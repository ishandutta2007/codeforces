import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b, c, x, y) = readLine()!!.split(" ").map { it.toInt() }
        println(if (max(0, x - a) + max(0, y - b) <= c) "yEs" else "nO")
    }
}