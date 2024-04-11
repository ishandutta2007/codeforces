fun main() {
    val n = readLine()!!.toInt()
    val p = readLine()!!.split(" ").map { it.toInt() }
    val grid = Array(n) { IntArray(it + 1) }
    for (k in 0 until n) {
        var y = k
        var x = k
        for (j in 1..p[k]) {
            grid[y][x] = p[k]
            if (x > 0 && grid[y][x - 1] == 0) {
                x--
            } else {
                y++
            }
        }
    }
    val out = StringBuilder()
    grid.forEach { out.appendln(it.joinToString(" ")) }
    print(out)
}