import kotlin.math.max
import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val dp = IntArray(n + 2) { n }
        val s = readLine()!!
        val f = s.indexOfFirst { it == '*' }
        dp[f] = 1
        val l = s.indexOfLast { it == '*' }
        for (j in f + 1..l) {
            if (s[j] == '*') {
                for (j2 in max(f, j - k) until j) {
                    dp[j] = min(dp[j], dp[j2] + 1)
                }
            }
        }
        println(dp[l])
    }
}