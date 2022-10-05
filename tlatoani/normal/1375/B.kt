import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val grid = Array(n) { jin.readLine().split(" ").map { it.toInt() }.toIntArray() }
        for (y in 0 until n) {
            for (x in 0 until m) {
                if ((y == 0 || y == n - 1) && (x == 0 || x == m - 1)) {
                    if (grid[y][x] > 2) {
                        out.appendln("NO")
                        continue@cases
                    }
                    grid[y][x] = 2
                } else if ((y == 0 || y == n - 1) || (x == 0 || x == m - 1)) {
                    if (grid[y][x] > 3) {
                        out.appendln("NO")
                        continue@cases
                    }
                    grid[y][x] = 3
                } else {
                    if (grid[y][x] > 4) {
                        out.appendln("NO")
                        continue@cases
                    }
                    grid[y][x] = 4
                }
            }
        }
        out.appendln("YES")
        grid.forEach { out.appendln(it.joinToString(" ")) }
    }
    print(out)
}