import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, h) = readLine()!!.split(" ").map { it.toLong() }
        val weapons = readLine()!!.split(" ").map { it.toLong() }.sortedDescending()
        val answer = min(2L * ((h + weapons[0] + weapons[1] - 1L) / (weapons[0] + weapons[1])), 1L + (2L * ((h + weapons[1] - 1L) / (weapons[0] + weapons[1]))))
        println(answer)
    }
}