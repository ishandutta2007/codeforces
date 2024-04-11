import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    val grid = Array(n) { jin.readLine() }
    val allRows = grid.all { '#' in it }
    val allColumns = (0 until m).all { x -> (0 until n).any { y -> grid[y][x] == '#' } }
    if (allRows != allColumns) {
        println(-1)
        return
    }
    for (y in 0 until n) {
        var stage = 0
        for (x in 0 until m) {
            if (grid[y][x] == '#') {
                if (stage == 2) {
                    println(-1)
                    return
                } else {
                    stage = 1
                }
            } else {
                if (stage == 1) {
                    stage = 2
                }
            }
        }
    }
    for (x in 0 until m) {
        var stage = 0
        for (y in 0 until n) {
            if (grid[y][x] == '#') {
                if (stage == 2) {
                    println(-1)
                    return
                } else {
                    stage = 1
                }
            } else {
                if (stage == 1) {
                    stage = 2
                }
            }
        }
    }
    val seen = Array(n) { BooleanArray(m) }
    var answer = 0
    val stack = Stack<Int>()
    for (ry in 0 until n) {
        for (rx in 0 until m) {
            if (grid[ry][rx] == '#' && !seen[ry][rx]) {
                answer++
                seen[ry][rx] = true
                stack.push(ry)
                stack.push(rx)
                while (stack.isNotEmpty()) {
                    val x = stack.pop()
                    val y = stack.pop()
                    if (y > 0 && grid[y - 1][x] == '#' && !seen[y - 1][x]) {
                        seen[y - 1][x] = true
                        stack.push(y - 1)
                        stack.push(x)
                    }
                    if (y < n - 1 && grid[y + 1][x] == '#' && !seen[y + 1][x]) {
                        seen[y + 1][x] = true
                        stack.push(y + 1)
                        stack.push(x)
                    }
                    if (x > 0 && grid[y][x - 1] == '#' && !seen[y][x - 1]) {
                        seen[y][x - 1] = true
                        stack.push(y)
                        stack.push(x - 1)
                    }
                    if (x < m - 1 && grid[y][x + 1] == '#' && !seen[y][x + 1]) {
                        seen[y][x + 1] = true
                        stack.push(y)
                        stack.push(x + 1)
                    }
                }
            }
        }
    }
    println(answer)
}