import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val (a, va) = readLine()!!.split(" ").map { it.toInt() }
        val (c, vc) = readLine()!!.split(" ").map { it.toInt() }
        val b = readLine()!!.toInt()
        println(min(vc, va + (b - a)))
    }
}