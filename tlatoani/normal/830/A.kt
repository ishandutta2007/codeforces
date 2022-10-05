import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k, p) = jin.readLine().split(" ").map { it.toInt() }
    val people = jin.readLine().split(" ").map { it.toInt() }.sorted()
    val keys = jin.readLine().split(" ").map { it.toInt() }.sorted()
    val dp = Array(n + 1) { LongArray(k + 1) { Long.MAX_VALUE } }
    dp[0].fill(0L)
    for (a in 1..n) {
        for (b in a..k) {
            dp[a][b] = min(dp[a][b - 1], max(dp[a - 1][b - 1], abs(people[a - 1] - keys[b - 1]).toLong() + abs(keys[b - 1] - p).toLong()))
        }
    }
    println(dp[n][k])
}