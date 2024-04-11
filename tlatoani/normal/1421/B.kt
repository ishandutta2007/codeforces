import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val grid = Array(n) { jin.readLine() }
        val answer = mutableListOf<Pair<Int, Int>>()
        if (grid[1][0] == grid[0][1]) {
            if (grid[n - 1][n - 2] == grid[1][0]) {
                answer.add(Pair(n - 1, n - 2))
            }
            if (grid[n - 2][n - 1] == grid[1][0]) {
                answer.add(Pair(n - 2, n - 1))
            }
        } else if (grid[n - 1][n - 2] == grid[n - 2][n - 1]) {
            if (grid[1][0] == grid[n - 1][n - 2]) {
                answer.add(Pair(1, 0))
            }
            if (grid[0][1] == grid[n - 1][n - 2]) {
                answer.add(Pair(0, 1))
            }
        } else {
            if (grid[1][0] == '0') {
                answer.add(Pair(1, 0))
            }
            if (grid[0][1] == '0') {
                answer.add(Pair(0, 1))
            }
            if (grid[n - 1][n - 2] == '1') {
                answer.add(Pair(n - 1, n - 2))
            }
            if (grid[n - 2][n - 1] == '1') {
                answer.add(Pair(n - 2, n - 1))
            }
        }
        println(answer.size)
        println(answer.joinToString("\n") { "${it.first + 1} ${it.second + 1}"})
    }
}