import kotlin.math.abs
import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val hs = listOf(0L) + readLine()!!.split(" ").map { it.toLong() } + listOf(0L)
        var answer = 0L
        for (j in 1..n + 1) {
            answer += abs(hs[j] - hs[j - 1])
        }
        for (j in 1..n) {
            if (hs[j] > max(hs[j - 1], hs[j + 1])) {
                answer -= hs[j] - max(hs[j - 1], hs[j + 1])
            }
        }
        println(answer)
    }
}