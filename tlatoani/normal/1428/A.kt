import kotlin.math.abs

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (x1, y1, x2, y2) = readLine()!!.split(" ").map { it.toInt() }
        println(abs(x2 - x1) + abs(y2 - y1) + (if (x2 != x1 && y2 != y1) 2 else 0))
    }
}