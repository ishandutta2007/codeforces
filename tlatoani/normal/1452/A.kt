import kotlin.math.max

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }.sorted()
        println(max(x + y, (2 * y) - 1))
    }
}