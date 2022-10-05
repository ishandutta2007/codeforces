import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val ay = readLine()!!.split(" ").map { it.toLong() }
    val by = readLine()!!.split(" ").map { it.toLong() }
    val dp = Array(n) { LongArray(n) }
    var answer = 0L
    for (x in n - 1 downTo 0) {
        for (y in x + 1 until n) {
            dp[x][y] = ((ay[x] - ay[y]) * (by[y] - by[x])) + dp[x + 1][y - 1]
            answer = max(answer, dp[x][y])
        }
    }
    for (x in 0 until n) {
        answer += ay[x] * by[x]
    }
    println(answer)
}