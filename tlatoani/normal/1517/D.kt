import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jim = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, k) = jim.readLine().split(" ").map { it.toInt() }
    if (k % 2 == 1) {
        for (y in 1..n) {
            println("-1 ".repeat(m))
        }
    } else {
        val exhibits = Array((2 * n) + 2) { IntArray((2 * m) + 2) }
        for (y in 1..n) {
            val tokenizer = StringTokenizer(jim.readLine())
            for (x in 2..m) {
                exhibits[2 * y][(2 * x) - 1] = tokenizer.nextToken().toInt()
            }
        }
        for (y in 2..n) {
            val tokenizer = StringTokenizer(jim.readLine())
            for (x in 1..m) {
                exhibits[(2 * y) - 1][2 * x] = tokenizer.nextToken().toInt()
            }
        }
        val dp = Array((k / 2) + 1) { j -> Array(n + 2) { y -> IntArray(m + 2) { x -> if (j == 0 && y in 1..n && x in 1..m) 0 else 1000000000 } } }
        for (j in 1..k / 2) {
            for (y in 1..n) {
                for (x in 1..m) {
                    dp[j][y][x] = min(dp[j][y][x], dp[j - 1][y - 1][x] + exhibits[(2 * y) - 1][2 * x])
                    dp[j][y][x] = min(dp[j][y][x], dp[j - 1][y + 1][x] + exhibits[(2 * y) + 1][2 * x])
                    dp[j][y][x] = min(dp[j][y][x], dp[j - 1][y][x - 1] + exhibits[2 * y][(2 * x) - 1])
                    dp[j][y][x] = min(dp[j][y][x], dp[j - 1][y][x + 1] + exhibits[2 * y][(2 * x) + 1])
                }
            }
        }
        val out = StringBuilder()
        for (y in 1..n) {
            for (x in 1..m) {
                out.append(2L * dp[k / 2][y][x]).append(' ')
            }
            out.appendln()
        }
        print(out)
    }
}