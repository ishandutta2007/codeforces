import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ").map { it.toInt() }
    val n = line[0]
    val m = line[1]
    val k = line[2]
    val dp = IntArray(n + 1) { Int.MAX_VALUE }
    dp[k] = 0
    for (j in 1..m) {
        val line = jin.readLine().split(" ").map { it.toInt() }
        val a = line[0]
        val b = line[1]
        val prevA = dp[a]
        val prevB = dp[b]
        if (prevA != Int.MAX_VALUE) {
            dp[a]++
        }
        if (prevB != Int.MAX_VALUE) {
            dp[b]++
        }
        if (prevB != Int.MAX_VALUE) {
            dp[a] = min(dp[a], prevB)
        }
        if (prevA != Int.MAX_VALUE) {
            dp[b] = min(dp[b], prevA)
        }
    }
    println(dp.map { if (it == Int.MAX_VALUE) -1 else it }.subList(1, n + 1).joinToString(" "))
}