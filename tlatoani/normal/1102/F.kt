import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val matrix = Array(n) { jin.readLine().split(" ").map { it.toInt() } }
    val md = Array(n) { j -> IntArray(n) { k -> (0 until m).map { abs(matrix[j][it] - matrix[k][it]) }.min()!! } }
    var answer = 0
    for (s in 0 until n) {
        val dp = Array(n) { IntArray(1 shl n) }
        dp[s][1 shl s] = Int.MAX_VALUE
        for (mask in 1 until (1 shl n)) {
            for (j in 0 until n) {
                if ((mask shr j) and 1 != 0) {
                    for (k in 0 until n) {
                        if (k != j && (mask shr k) and 1 != 0) {
                            dp[j][mask] = max(dp[j][mask], min(md[j][k], dp[k][mask - (1 shl j)]))
                        }
                    }
                }
            }
        }
        for (k in 0 until n) {
            var pos = dp[k].last()
            for (x in 1 until m) {
                pos = min(pos, abs(matrix[k][x - 1] - matrix[s][x]))
            }
            answer = max(pos, answer)
        }
    }
    println(answer)
}