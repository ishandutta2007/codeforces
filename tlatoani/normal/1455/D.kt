import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, x) = readLine()!!.split(" ").map { it.toInt() }
        val ay = readLine()!!.split(" ").map { it.toInt() }.toList()
        val sy = (listOf(x) + ay).sorted()
        var answer = Int.MAX_VALUE
        for (j in 0..n) {
            val meta = sy.subList(0, j) + sy.subList(j + 1, n + 1)
            if ((0 until n).all { ay[it] >= meta[it] && (ay[it] == meta[it] || ay[it] > x) }) {
                answer = min(answer, (0 until n).count { ay[it] > meta[it] })
            }
        }
        println(if (answer == Int.MAX_VALUE) -1 else answer)
    }
}