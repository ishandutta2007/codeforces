import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val m = jin.readLine().substringAfter(' ').toInt()
    val freq = IntArray(m + 4)
    for (k in jin.readLine().split(" ")) {
        freq[k.toInt() + 1]++
    }
    val dp = Array(3) { Array(5) { IntArray(m + 4) { Int.MAX_VALUE } } }
    dp[0][0][1] = 0
    for (j in 2..m + 3) {
        for (a in 0..2) {
            for (b in 0..2) {
                for (c in 0..2) {
                    if (freq[j] >= a && freq[j - 1] >= a + b && freq[j - 2] >= a + b + c && dp[b][b + c][j - 1] != Int.MAX_VALUE) {
                        dp[a][a + b][j] = min(dp[a][a + b][j], dp[b][b + c][j - 1] + ((freq[j - 2] - a - b - c) % 3))
                    }
                }
            }
        }
    }
    println((freq.sum() - dp[0][0][m + 3]) / 3)
}