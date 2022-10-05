import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val x = ay.indexOf(1)
        val y = ay.indexOf(n)
        println(minOf(min(x, y) + 1 + n - max(x, y), max(x, y) + 1, n - min(x, y)))
    }
}