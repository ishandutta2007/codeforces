fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val grid = Array(n) { readLine()!! }
        val dp = Array(n) { IntArray(m) }
        var answer = 0
        for (y in n - 1 downTo 0) {
            for (x in 0 until m) {
                if (grid[y][x] == '*') {
                    dp[y][x] = 1 + if (y == n - 1) 0 else minOf(if (x == 0) 0 else dp[y + 1][x - 1], dp[y + 1][x], if (x == m - 1) 0 else dp[y + 1][x + 1])
                    answer += dp[y][x]
                }
            }
        }
        println(answer)
    }
}