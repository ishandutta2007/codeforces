import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    val t = line[2].toInt()
    val grid = arrayOf("2".repeat(m + 2)) + Array(n) { '2' + jin.readLine() + '2' } + arrayOf("2".repeat(m + 2))
    val time = Array(n + 2) { IntArray(m + 2) { -1 } }
    val q = LinkedList<Int>()
    for (y in 1..n) {
        for (x in 1..m) {
            if (grid[y][x] == grid[y - 1][x] || grid[y][x] == grid[y + 1][x] || grid[y][x] == grid[y][x - 1] || grid[y][x] == grid[y][x + 1]) {
                time[y][x] = 0
                q.add(y)
                q.add(x)
            }
        }
    }
    while (q.isNotEmpty()) {
        val y = q.remove()
        val x = q.remove()
        if (time[y - 1][x] == -1 && grid[y - 1][x] != '2') {
            time[y - 1][x] = time[y][x] + 1
            q.add(y - 1)
            q.add(x)
        }
        if (time[y + 1][x] == -1 && grid[y + 1][x] != '2') {
            time[y + 1][x] = time[y][x] + 1
            q.add(y + 1)
            q.add(x)
        }
        if (time[y][x - 1] == -1 && grid[y][x - 1] != '2') {
            time[y][x - 1] = time[y][x] + 1
            q.add(y)
            q.add(x - 1)
        }
        if (time[y][x + 1] == -1 && grid[y][x + 1] != '2') {
            time[y][x + 1] = time[y][x] + 1
            q.add(y)
            q.add(x + 1)
        }
    }
    val out = StringBuilder()
    for (j in 1..t) {
        val line = jin.readLine().split(" ")
        val y = line[0].toInt()
        val x = line[1].toInt()
        val p = line[2].toLong()
        var answer = grid[y][x] - '0'
        if (time[y][x] == -1 || p <= time[y][x]) {
            if (p % 2L == 1L) {
                answer = 1 - answer
            }
        } else {
            if (time[y][x] % 2 == 1) {
                answer = 1 - answer
            }
        }
        if (p % 2L == 1L) {
            answer = 1 - answer
        }
        out.appendln(answer)
    }
    print(out)
}