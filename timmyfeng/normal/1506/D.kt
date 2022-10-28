import kotlin.math.*

fun main() {
    val t = readLine()!!.toInt()
    for (i in 0 until t) {
        val n = readLine()!!.toInt()
        val tally = readLine()!!.split(" ").groupingBy { it.toInt() }.eachCount()
        println(max(n % 2, 2 * tally.values.maxOf { it } - n))
    }
}