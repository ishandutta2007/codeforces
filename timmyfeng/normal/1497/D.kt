import kotlin.math.*

fun main() {
    for (t in 0 until readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tag = readLine()!!.split(" ").map { it.toInt() }
        val score = readLine()!!.split(" ").map { it.toLong() }

        val points = LongArray(n)
        for (i in 1 until n) {
            for (j in i - 1 downTo 0) {
                if (tag[i] != tag[j]) {
                    val w = abs(score[i] - score[j])
                    val temp = points[i]
                    points[i] = max(points[i], points[j] + w)
                    points[j] = max(points[j], temp + w)
                }
            }
        }

        println(points.maxOf { it })
    }
}