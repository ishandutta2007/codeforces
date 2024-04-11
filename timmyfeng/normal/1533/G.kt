import java.io.*

val VECTORS = arrayOf(0 to 1, 1 to 0, 0 to -1, -1 to 0)

lateinit var grid: Array<List<Int>>
lateinit var visited: Array<BooleanArray>
lateinit var eulerTour: MutableList<Int>

fun dfs(i: Int, j: Int) {
    visited[i][j] = true
    eulerTour.add(grid[i][j])
    for ((deltaI, deltaJ) in VECTORS) {
        val newI = i + deltaI
        val newJ = j + deltaJ
        if (0 <= newI && newI < grid.size && 0 <= newJ && newJ < grid[0].size) {
            if (grid[newI][newJ] != 0 && !visited[newI][newJ]) {
                dfs(newI, newJ)
                eulerTour.add(grid[i][j])
            }
        }
    }
}

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    var t = reader.readLine().toInt()
    while (t-- > 0) {
        val (n, m) = reader.readLine().split(" ").map { it.toInt() }

        grid = Array(n) { reader.readLine().split(" ").map { it.toInt() } }
        visited = Array(n) { BooleanArray(m) { false } }
        eulerTour = mutableListOf()
        var ok = true

        for (i in 0 until n) {
            for (j in 0 until m) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    if (eulerTour.isNotEmpty()) {
                        ok = false
                    } else {
                        dfs(i, j)
                    }
                }
            }
        }

        if (ok) {
            val size = eulerTour.size / 2 + 1
            writer.println("$size $size")
            for (i in 0 until size) {
                for (j in 0 until size) {
                    writer.print("${eulerTour[i + j]} ")
                }
                writer.println()
            }
        } else {
            writer.println(-1)
        }
    }

    writer.close()
}