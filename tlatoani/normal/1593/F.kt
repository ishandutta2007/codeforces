import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, a, b) = readLine()!!.split(" ").map { it.toInt() }
        val dp = Array(n + 1) { Array(n + 1) { Array(a) { IntArray(b) } } }
        dp[0][0][0][0] = 2
        val powA = IntArray(n + 1)
        val powB = IntArray(n + 1)
        powA[0] = 1
        powB[0] = 1
        for (j in 1..n) {
            powA[j] = (10 * powA[j - 1]) % a
            powB[j] = (10 * powB[j - 1]) % b
        }
        val s = readLine()!!.map { it - '0' }.reversed()
        for (j in 0 until n) {
            for (m1 in 0..j) {
                val m2 = j - m1
                for (x in 0 until a) {
                    for (y in 0 until b) {
                        if (dp[m1][m2][x][y] != 0) {
                            dp[m1 + 1][m2][(x + (powA[m1] * s[j])) % a][y] = 1
                            dp[m1][m2 + 1][x][(y + (powB[m2] * s[j])) % b] = -1
                        }
                    }
                }
            }
        }
        var bestM1 = -1
        for (m1 in 1 until n) {
            val m2 = n - m1
            if (dp[m1][m2][0][0] != 0 && abs(m1 - m2) < abs(bestM1 - (n - bestM1))) {
                bestM1 = m1
            }
        }
        if (bestM1 == -1) {
            println(-1)
        } else {
            var m1 = bestM1
            var m2 = n - m1
            var x = 0
            var y = 0
            while (m1 + m2 != 0) {
                if (dp[m1][m2][x][y] == 1) {
                    print("R")
                    m1--
                    x -= powA[m1] * s[m1 + m2]
                    x %= a
                    x += a
                    x %= a
                } else {
                    print("B")
                    m2--
                    y -= powB[m2] * s[m1 + m2]
                    y %= b
                    y += b
                    y %= b
                }
            }
            println()
        }
    }
}