import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val grid = Array(n) { jin.readLine() }
    val order = mutableListOf<Pair<Int, Int>>()
    val seen = Array(n) { BooleanArray(m) }
    fun visit(y: Int, x: Int, needSand: Boolean) {
        if (y in 0 until n && x in 0 until m && (!needSand || grid[y][x] == '#') && !seen[y][x]) {
            seen[y][x] = true
            visit(y + 1, x, false)
            visit(y - 1, x, true)
            visit(y, x - 1, true)
            visit(y, x + 1, true)
            order.add(Pair(y, x))
        }
    }
    for (y in 0 until n) {
        for (x in 0 until m) {
            visit(y, x, false)
        }
    }
    seen.forEach { it.fill(false) }
    var answer = 0
    for ((y, x) in order.reversed()) {
        if (grid[y][x] == '#' && !seen[y][x]) {
            answer++
            fun assign(y: Int, x: Int, needSand: Boolean) {
                if (y in 0 until n && x in 0 until m && (!needSand || grid[y][x] == '#') && !seen[y][x]) {
                    seen[y][x] = true
                    assign(y + 1, x, false)
                    assign(y - 1, x, true)
                    assign(y, x - 1, true)
                    assign(y, x + 1, true)
                }
            }
            assign(y, x, false)
        }
    }
    println(answer)
}