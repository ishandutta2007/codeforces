import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val s = jin.readLine()
        val t = jin.readLine()
        if (s.toList().sorted() != t.toList().sorted()) {
            println(-1)
        } else {
            val sumsS = Array(26) { IntArray(n + 1) }
            val sumsT = Array(26) { IntArray(n + 1) }
            for (j in n - 1 downTo 0) {
                for (chara in 0..25) {
                    sumsS[chara][j] = sumsS[chara][j + 1]
                    sumsT[chara][j] = sumsT[chara][j + 1]
                }
                sumsS[s[j] - 'a'][j]++
                sumsT[t[j] - 'a'][j]++
            }
            val dp = Array(n + 1) { IntArray(n + 1) { 115115 } }
            dp[0][0] = 0
            for (j in 0..n) {
                for (k in max(1, j)..n) {
                    if (j > 0) {
                        dp[j][k] = 1 + dp[j - 1][k]
                        if (s[j - 1] == t[k - 1]) {
                            dp[j][k] = min(dp[j][k], dp[j - 1][k - 1])
                        }
                    }
                    if (sumsS[t[k - 1] - 'a'][j] > sumsT[t[k - 1] - 'a'][k]) {
                        dp[j][k] = min(dp[j][k], dp[j][k - 1])
                    }
                }
            }
            println(dp[n][n])
        }
    }
}