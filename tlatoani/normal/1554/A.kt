import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toLong() }
        println((1 until n).map { xs[it - 1] * xs[it] }.max())
    }
}