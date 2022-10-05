import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val grid = Array(n) { jin.readLine().toCharArray() }
        val spots = Array(3) { Array(2) { mutableListOf<Pair<Int, Int>>() } }
        for (y in 0 until n) for (x in 0 until n) {
            if (grid[y][x] != '.') {
                spots[(y + x) % 3][if (grid[y][x] == 'O') 0 else 1].add(Pair(y, x))
            }
        }
        spots.sortBy { it.sumBy { it.size } }
        val lists = listOf(spots[0][0] + spots[1][1], spots[0][1] + spots[1][0])
        for ((y, x) in lists.minBy { it.size }!!) {
            grid[y][x] = if (grid[y][x] == 'O') 'X' else 'O'
        }
        grid.forEach { out.appendln(it) }
    }
    print(out)
}