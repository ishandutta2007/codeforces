import kotlin.math.abs

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val balls = Array(n) {
            readLine()!!.split(" ").map { it.toInt() }
        }
        println(if (balls.any { (x, y) -> balls.all { (a, b) -> abs(a - x) + abs(b - y) <= k }}) 1 else -1)
    }
}