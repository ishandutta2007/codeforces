import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = max(readLine()!!.toLong(), 6L)
        println(5L * ((n + 1L) / 2L))
    }
}