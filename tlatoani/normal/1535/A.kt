import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b, c, d) = readLine()!!.split(" ").map { it.toInt() }
        println(if (min(max(a, b), max(c, d)) == listOf(a, b, c, d).sortedDescending()[1]) "YES" else "NO")
    }
}