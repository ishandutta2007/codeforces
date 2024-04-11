import java.lang.StringBuilder
import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val answer = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        var dp = Array(2) { Pair(0, 0L) }
        for (i in 1..n) {
            val a = jin.nextInt()
            val b = jin.nextLong()
            dp = arrayOf(
                    Pair(a, if (dp[0].first == a) dp[1].second else dp[0].second),
                    Pair(a + 1, (if (dp[0].first == a + 1) dp[1].second else dp[0].second) + b),
                    Pair(a + 2, (if (dp[0].first == a + 2) dp[1].second else dp[0].second) + (2L * b))
            )
            dp.sortBy { it.second }
            //println("dp[$i] = ${dp.contentToString()}")
        }
        answer.append(dp[0].second)
        answer.append('\n')
    }
    print(answer)
}