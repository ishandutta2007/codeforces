fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
        val answer = Array(n) { CharArray(m) { ' ' } }
        fun letter(y: Int, x: Int) = 'a' + (5 * (y % 5)) + (x % 5)
        fun addHorizontal(y: Int, x: Int) {
            answer[y][x] = letter(y, x)
            answer[y][x + 1] = letter(y, x)
        }
        fun addVertical(y: Int, x: Int) {
            answer[y][x] = letter(y, x)
            answer[y + 1][x] = letter(y, x)
        }
        if (n % 2 == 0) {
            if (k % 2 == 0 && (m % 2 == 0 || 2 * k <= n * (m - 1))) {
                println("YES")
                for (j in 0 until k / 2) {
                    addHorizontal(2 * (j / (m / 2)), 2 * (j % (m / 2)))
                    addHorizontal(1 + (2 * (j / (m / 2))), 2 * (j % (m / 2)))
                }
                for (y in 0 until n) {
                    for (x in 0 until m) {
                        if (answer[y][x] == ' ') {
                            addVertical(y, x)
                        }
                    }
                }
                answer.forEach { println(it) }
            } else {
                println("NO")
            }
        } else {
            if (k >= m / 2 && (k - (m / 2)) % 2 == 0) {
                println("YES")
                for (j in 0 until (m / 2)) {
                    addHorizontal(0, 2 * j)
                }
                for (j in 0 until (k - (m / 2)) / 2) {
                    addHorizontal(1 + (2 * (j / (m / 2))), 2 * (j % (m / 2)))
                    addHorizontal(2 + (2 * (j / (m / 2))), 2 * (j % (m / 2)))
                }
                for (y in 0 until n) {
                    for (x in 0 until m) {
                        if (answer[y][x] == ' ') {
                            addVertical(y, x)
                        }
                    }
                }
                answer.forEach { println(it) }
            } else {
                println("NO")
            }
        }
    }
}