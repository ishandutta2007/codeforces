import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val s = (" " + jin.readLine() + " ").map { it - 'a' }
    val t = (" " + jin.readLine() + " ").map { it - 'a' }
    fun calcDP(s: List<Int>, t: List<Int>): IntArray {
        val dp = IntArray(n + 2)
        var last = IntArray(26)
        for (j in 1..n) {
            dp[j] = dp[last[s[j]]]
            for (prev in 0..25) {
                if (t[dp[last[prev]] + 1] == s[j]) {
                    dp[j] = max(dp[j], dp[last[prev]] + 1)
                }
            }
            last[s[j]] = j
        }
        for (j in 1..n) {
            dp[j] = max(dp[j], dp[j - 1])
        }
        return dp
    }
    val dpForward = calcDP(s, t)
    val dpBackward = calcDP(s.reversed(), t.reversed()).reversedArray()
    var answer = 0
    for (j in 2..n) {
        if (dpBackward[j] > 0 && dpForward[j - 1] > 0 && dpForward[j - 1] + dpBackward[j] >= m) {
            var upper = j - 1
            var lower = 1
            while (upper > lower) {
                val mid = (upper + lower) / 2
                if (dpForward[mid] > 0 && dpForward[mid] + dpBackward[j] >= m) {
                    upper = mid
                } else {
                    lower = mid + 1
                }
            }
            answer = max(answer, j - upper)
        }
    }
    println(answer)
}