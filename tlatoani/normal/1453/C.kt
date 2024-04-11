import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val grid = Array(n) { jin.readLine().map { it - '0' }.toIntArray() }
        fun reverse() = grid.forEach { it.reverse() }
        fun transpose() {
            for (y in 0 until n) {
                for (x in 0 until y) {
                    val temp = grid[y][x]
                    grid[y][x] = grid[x][y]
                    grid[x][y] = temp
                }
            }
        }
        var answer = IntArray(10)
        for (j in 0..3) {
            var res = calc(n, grid)
            for (d in 0..9) {
                answer[d] = max(answer[d], res[d])
            }
            reverse()
            res = calc(n, grid)
            for (d in 0..9) {
                answer[d] = max(answer[d], res[d])
            }
            transpose()
        }
        println(answer.joinToString(" "))
    }
}

fun calc(n: Int, grid: Array<IntArray>): IntArray {
    val highest = IntArray(10) { n + 1 }
    for (y in 0 until n) for (x in 0 until n) {
        highest[grid[y][x]] = min(highest[grid[y][x]], y)
    }
    val leftmost = IntArray(10)
    var res = IntArray(10)
    for (y in 0 until n) {
        leftmost.fill(n + 1)
        for (x in 0 until n) {
            leftmost[grid[y][x]] = min(leftmost[grid[y][x]], x)
            res[grid[y][x]] = maxOf(res[grid[y][x]], max(0, x - leftmost[grid[y][x]]) * y, x * max(0, y - highest[grid[y][x]]))
        }
    }
    return res
}