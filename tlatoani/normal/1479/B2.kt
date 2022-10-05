import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val dp = IntArray(n + 1)
    var delta = 1
    var minimo = 0
    var prev = 0
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        var next = min(minimo + 1, dp[k])
        if (k != prev) {
            delta++
            next--
        }
        dp[prev] = min(dp[prev], next)
        minimo = min(minimo, next)
        prev = k
    }
    println(minimo + delta)
}