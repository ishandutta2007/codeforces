import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val k = jin.nextInt()
    jin.nextLine()
    val s = "0" + jin.nextLine()
    val dp = LongArray(n + k + 1)
    val queue = LinkedList<Pair<Int, Long>>()
    queue.addLast(Pair(0, 0L))
    var answer = Long.MAX_VALUE
    for (i in 1..n + k) {
        while (i - (2 * k) - 1 > queue.first().first) {
            queue.removeFirst()
        }
        dp[i] = i.toLong() + dp[i - 1]
        if (i > k && s[i - k] == '1') {
            dp[i] = min(dp[i], (i - k).toLong() + queue.first.second)
        }
        if (i >= n) {
            answer = min(answer, dp[i])
        }
        while (queue.isNotEmpty() && queue.last.second >= dp[i]) {
            queue.removeLast()
        }
        queue.addLast(Pair(i, dp[i]))
    }
    println(answer)
}