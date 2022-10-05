fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val grid = Array(n + 1) { y -> if (y == n) IntArray(m + 1) else (readLine()!! + "W").map { if (it == 'W') 0 else 1 }.toIntArray() }
    var answer = 0
    for (y in 0 until n) {
        for (x in 0 until m) {
            grid[y][x] = grid[y][x] xor grid[y + 1][x] xor grid[y][x + 1] xor grid[y + 1][x + 1]
            if (grid[y][x] == 1) {
                answer++
            }
        }
    }
    var found = false
    for (y in 0 until n - 1) {
        for (x in 0 until m - 1) {
            if (grid[y][x] == 1 && grid[n - 1][x] == 1 && grid[y][m - 1] == 1 && grid[n - 1][m - 1] == 1) {
                found = true
            }
        }
    }
    if (found) {
        answer--
    }
    println(answer)
}