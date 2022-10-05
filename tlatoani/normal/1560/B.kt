import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        val p = abs(a - b)
        if (maxOf(a, b, c) > 2 * p) {
            println(-1)
        } else {
            var d = c + p
            if (d > 2 * p) {
                d -= 2 * p
            }
            println(d)
        }
    }
}