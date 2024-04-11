import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val k = jin.nextLong()
    val grid = Array(n) { LongArray(m) { jin.nextLong() } }
    val mid = (n + m - 2) / 2
    val dpUp = Array(n) { Array(m) { mutableMapOf<Long, Long>() } }
    dpUp[0][0][grid[0][0]] = 1L
    for (y in 0 until n) {
        for (x in 0 until m) {
            if (y + x <= mid) {
                if (y > 0) {
                    for ((mask, freq) in dpUp[y - 1][x]) {
                        dpUp[y][x][mask xor grid[y][x]] = freq
                    }
                }
                if (x > 0) {
                    for ((mask, freq) in dpUp[y][x - 1]) {
                        dpUp[y][x][mask xor grid[y][x]] = (dpUp[y][x][mask xor grid[y][x]] ?: 0L) + freq
                    }
                }
            }
        }
    }
    val dpDown = Array(n) { Array(m) { mutableMapOf<Long, Long>() } }
    dpDown[n - 1][m - 1][k] = 1L
    var answer = 0L
    for (y in n - 1 downTo 0) {
        for (x in m - 1 downTo 0) {
            if (y + x >= mid) {
                if (y < n - 1) {
                    for ((mask, freq) in dpDown[y + 1][x]) {
                        dpDown[y][x][mask xor grid[y + 1][x]] = freq
                    }
                }
                if (x < m - 1) {
                    for ((mask, freq) in dpDown[y][x + 1]) {
                        dpDown[y][x][mask xor grid[y][x + 1]] = (dpDown[y][x][mask xor grid[y][x + 1]] ?: 0L) + freq
                    }
                }
            }
            if (y + x == mid) {
                for ((mask, freq) in dpDown[y][x]) {
                    answer += (dpUp[y][x][mask] ?: 0L) * freq
                }
            }
        }
    }
    println(answer)
}