import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (nl, r1, r2, r3, d) = jin.readLine().split(" ").map { it.toLong() }
    val n = nl.toInt()
    val levels = listOf(0L) + jin.readLine().split(" ").map { it.toLong() }
    val dp = LongArray(n + 1)
    fun solo(j: Int) = min((r1 * levels[j]) + r3, d + d + min(r1 * (levels[j] + 2L), r2 + r1))
    fun optimal(j: Int) = minOf((r1 * levels[j]) + r3, r1 * (levels[j] + 2L), r2 + r1)
    dp[1] = solo(1)
    for (j in 2..n) {
        dp[j] = min(dp[j - 1] + solo(j), dp[j - 2] + d + d + optimal(j - 1) + optimal(j))
    }
    //println(dp.contentToString())
    var answer = dp[n]
    var curr = solo(n)
    for (j in n - 1 downTo 1) {
        curr += d + optimal(j)
        //println("j = $j, pos = ${dp[j - 1] + curr}")
        answer = min(answer, dp[j - 1] + curr)
    }
    println(answer + ((n - 1).toLong() * d))
}