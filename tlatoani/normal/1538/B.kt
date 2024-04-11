import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val s = ay.sum()
        if (s % n == 0) {
            println(ay.count { it > s / n })
        } else {
            println(-1)
        }
    }
}