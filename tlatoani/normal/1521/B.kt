import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val k = ay.withIndex().minBy { it.value }!!.index
        println(n - 1)
        for (j in 0 until n) {
            if (j != k) {
                println("${k + 1} ${j + 1} ${ay[k]} ${ay[k] + abs(j - k)}")
            }
        }
    }
}