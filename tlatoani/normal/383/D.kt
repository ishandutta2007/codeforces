import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MOD = 1000000007L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val dp = LongArray(20001)
    var sum = 0
    var answer = 0L
    val tokenizer = StringTokenizer(jin.readLine())
    for (ix in 1..n) {
        val k = tokenizer.nextToken().toInt()
        dp[sum]++
        dp[sum] %= MOD
        for (j in 20000 downTo 2 * k) {
            dp[j] += dp[j - (2 * k)]
            dp[j] %= MOD
        }
        sum += k
        answer += dp[sum]
        answer %= MOD
    }
    println(answer)
}