import java.util.*
import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, ks) = readLine()!!.split(" ").map { it.toInt() }
        val k = ks.toLong()
        val dp = Array((2 * n) + 1) { LongArray(2) }
        val tokenizer = StringTokenizer(readLine()!!)
        for (j in 1L..n.toLong()) {
            val x = tokenizer.nextToken().toInt()
            if (j > dp[x][0]) {
                dp[x][1] = dp[x][0]
                dp[x][0] = j
            } else if (j > dp[x][1]) {
                dp[x][1] = j
            }
        }
        for (mask in 1..2 * n) {
            for (d in 0..17) {
                if ((mask shr d) and 1 == 1) {
                    val submask = mask - (1 shl d)
                    if (dp[submask][0] > dp[mask][0]) {
                        dp[mask][1] = dp[mask][0]
                        dp[mask][0] = dp[submask][0]
                        if (dp[submask][1] > dp[mask][1]) {
                            dp[mask][1] = dp[submask][1]
                        }
                    } else if (dp[submask][0] > dp[mask][1] && dp[submask][0] != dp[mask][0]) {
                        dp[mask][1] = dp[submask][0]
                    }
                }
            }
        }
        var answer = Long.MIN_VALUE
        for (mask in 0..2 * n) {
            if (dp[mask][1] != 0L) {
                answer = max(answer, (dp[mask][0] * dp[mask][1]) - (k * mask.toLong()))
            }
        }
        println(answer)
    }
}