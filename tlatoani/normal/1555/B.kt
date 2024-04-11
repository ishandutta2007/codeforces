import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (w, h) = readLine()!!.split(" ").map { it.toInt() }
        val (x1, y1, x2, y2) = readLine()!!.split(" ").map { it.toInt() }
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        var answer = Int.MAX_VALUE
        if (x1 > a) {
            answer = 0
        } else if (x2 + (a - x1) <= w) {
            answer = min(answer, a - x1)
        }
        if (y1 > b) {
            answer = 0
        } else if (y2 + (b - y1) <= h) {
            answer = min(answer, b - y1)
        }
        if (x2 + a <= w) {
            answer = 0
        } else if (x1 - (a - (w - x2)) >= 0) {
            answer = min(answer, a - (w - x2))
        }
        if (y2 + b <= h) {
            answer = 0
        } else if (y1 - (b - (h - y2)) >= 0) {
            answer = min(answer, b - (h - y2))
        }
        if (answer == Int.MAX_VALUE) {
            answer = -1
        }
        println(answer)
    }
}