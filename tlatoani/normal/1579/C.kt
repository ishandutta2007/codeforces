fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
        val field = Array(n) { readLine()!! }
        val accounted = Array(n) { BooleanArray(m) }
        for (y in 0 until n) {
            for (x in 0 until m) {
                if (field[y][x] == '*') {
                    var d = 0
                    while (y - d >= 0 && x - d >= 0 && x + d < m && field[y - d][x - d] == '*' && field[y - d][x + d] == '*') {
                        d++
                    }
                    d--
                    if (d >= k) {
                        for (j in 0..d) {
                            accounted[y - j][x - j] = true
                            accounted[y - j][x + j] = true
                        }
                    }
                }
            }
        }
        var answer = "yEs"
        for (y in 0 until n) {
            for (x in 0 until m) {
                if (field[y][x] == '*' && !accounted[y][x]) {
                    answer = "nO"
                }
            }
        }
        println(answer)
    }
}