import java.util.*
import kotlin.math.min

fun main() {
    var n = readLine()!!.toInt()
    val tiles = mutableListOf<Int>()
    val tokenizer = StringTokenizer(readLine()!!)
    var prev = 0
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        if (k != prev) {
            tiles.add(k)
            prev = k
        }
    }
    n = tiles.size
    val dp = Array(n) { IntArray(n) { 115115 } }
    for (l in n - 1 downTo 0) {
        dp[l][l] = 0
        for (r in l + 1 until n) {
            dp[l][r] = (if (tiles[l] == tiles[r]) dp[l + 1][r - 1] else min(dp[l][r - 1], dp[l + 1][r])) + 1
        }
    }
    println(dp[0][n - 1])
}