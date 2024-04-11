import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val dp = IntArray(100001)
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        if (n == 1 && k == 1) {
            println(1)
            return
        }
        var prev = 0
        var f = 1
        while (f * f <= k) {
            if (k % f == 0) {
                prev = maxOf(prev, dp[f], dp[k / f])
            }
            f++
        }
        prev++
        f = 1
        while (f * f <= k) {
            if (k % f == 0) {
                dp[f] = prev
                dp[k / f] = prev
            }
            f++
        }
        dp[1] = 0
    }
    println(dp.max())
}