import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val m = readLine()!!.toInt()
        val matrix = Array(2) { readLine()!!.split(" ").map { it.toInt() } }
        var left = matrix[0].sum() - matrix[0][0]
        var right = 0
        var answer = max(left, right)
        for (j in 0 until m - 1) {
            left -= matrix[0][j + 1]
            right += matrix[1][j]
            answer = min(answer, max(left, right))
        }
        println(answer)
    }
}