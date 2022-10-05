import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    val a = tokenizer.nextToken().toInt()
    val b = tokenizer.nextToken().toInt()
    val image = Array(n) { jin.readLine() }
    val black = IntArray(m)
    for (x in 0 until m) {
        for (y in 0 until n) {
            if (image[y][x] == '#') {
                black[x]++
            }
        }
    }
    val dp = Array(2) { IntArray(m + 1) { 3000000 } }
    dp[0][0] = 0
    dp[1][0] = 0
    for (x in a..m) {
        for (color in 0..1) {
            var curr = 0
            for (xp in x - 1 downTo max(0, x - b)) {
                curr += if (color == 0) black[xp] else (n - black[xp])
                if (xp <= x - a) {
                    dp[color][x] = min(dp[color][x], dp[1 - color][xp] + curr)
                }
            }
        }
    }
    println(min(dp[0][m], dp[1][m]))
}