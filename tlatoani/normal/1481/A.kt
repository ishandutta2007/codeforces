import kotlin.math.abs

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (px, py) = readLine()!!.split(" ").map { it.toInt() }
        val directions = readLine()!!
        println(if (directions.count { it == if (px > 0) 'R' else 'L' } >= abs(px) && directions.count { it == if (py > 0) 'U' else 'D' } >= abs(py)) "yEs" else "nO")
    }
}