import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val k = line[1].toInt()
        val s = jin.readLine()
        val sums = IntArray(n + 1)
        for (j in 1..n) {
            sums[j] = sums[j - 1]
            if (s[j - 1] == '1') {
                sums[j]++
            }
        }
        var answer = sums[n]
        val dp = IntArray(n + 1)
        for (j in 1..n) {
            dp[j] = sums[j - 1]
            if (j > k) {
                dp[j] = min(dp[j], dp[j - k] + sums[j - 1] - sums[j - k])
            }
            dp[j] += ('1' - s[j - 1])
            answer = min(answer, dp[j] + sums[n] - sums[j])
        }
        out.appendln(answer)
    }
    print(out)
}