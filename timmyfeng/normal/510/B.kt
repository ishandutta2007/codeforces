import kotlin.system.exitProcess

val X = arrayOf(1, 0, -1, 0)
val Y = arrayOf(0, 1, 0, -1)

fun main() {

    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val grid = Array(n) { readLine()!! }

    val visited = Array(n) { BooleanArray(m) }

    fun dfs(x: Int, y: Int, p: Int) {
        visited[x][y] = true
        for (d in 0 until 4) {
            if (d != p) {
                val xNew = x + X[d]
                val yNew = y + Y[d]
                if (xNew >= 0 && yNew >= 0 && xNew < n && yNew < m && grid[x][y] == grid[xNew][yNew]) {
                    if (!visited[xNew][yNew]) {
                        dfs(xNew, yNew, (d + 2) % 4)
                    } else {
                        println("Yes")
                        exitProcess(0)
                    }
                }
            }
        }
    }

    for (i in 0 until n) {
        for (j in 0 until m) {
            if (!visited[i][j]) {
                dfs(i, j, -1)
            }
        }
    }

    println("No")
}