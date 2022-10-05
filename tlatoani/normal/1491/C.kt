import kotlin.math.max
import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val trampolines = (listOf(0) + readLine()!!.split(" ").map { it.toInt() }).toIntArray()
        val dp = LongArray(n + 2)
        var answer = 0L
        for (j in 1..n) {
            answer += max(0L, trampolines[j].toLong() - 1L - dp[j])
            for (k in j + 2..min(n, j + trampolines[j])) {
                dp[k]++
            }
            dp[j + 1] += max(0L, dp[j] - (trampolines[j].toLong() - 1L))
        }
        println(answer)
    }
}