import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val grid = Array(n) { jin.readLine() }
    val dp = Array(n) { IntArray(m) { 1 } }
    for (y in 2 until n) {
        for (x in 1 until m - 1) {
            if (grid[y][x] == grid[y - 1][x - 1] && grid[y][x] == grid[y - 1][x] && grid[y][x] == grid[y - 1][x + 1] && grid[y][x] == grid[y - 2][x]) {
                dp[y][x] = minOf(dp[y - 1][x - 1], dp[y - 1][x + 1], dp[y - 2][x]) + 1
            }
        }
    }
    println(dp.map { it.sum().toLong() }.sum())
}