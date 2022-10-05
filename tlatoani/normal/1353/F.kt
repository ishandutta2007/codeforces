import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val m = line[1].toInt()
        val grid = Array(n) { jin.readLine().split(" ").map { it.toLong() }.toLongArray() }
        val hs = mutableSetOf<Long>()
        for (y in 0 until n) {
            for (x in 0 until m) {
                grid[y][x] -= (y + x).toLong()
                hs.add(grid[y][x])
            }
        }
        val dp = Array(n) { LongArray(m) { Long.MAX_VALUE } }
        var answer = Long.MAX_VALUE
        for (h in hs) {
            dp.forEach { it.fill(Long.MAX_VALUE) }
            for (y in 0 until n) {
                for (x in 0 until m) {
                    if (grid[y][x] >= h) {
                        if (y == 0 && x == 0) {
                            dp[y][x] = 0L
                        } else {
                            if (y > 0 && dp[y - 1][x] != Long.MAX_VALUE) {
                                dp[y][x] = dp[y - 1][x]
                            }
                            if (x > 0 && dp[y][x - 1] != Long.MAX_VALUE) {
                                dp[y][x] = min(dp[y][x], dp[y][x - 1])
                            }
                        }
                        if (dp[y][x] != Long.MAX_VALUE) {
                            dp[y][x] += grid[y][x] - h
                        }
                    }
                }
            }
            answer = min(answer, dp[n - 1][m - 1])
        }
        println(answer)
    }
}