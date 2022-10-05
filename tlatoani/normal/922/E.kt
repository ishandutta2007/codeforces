import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val w = jin.nextLong()
    val b = jin.nextLong()
    val x = jin.nextLong()
    val c = IntArray(n) { jin.nextInt() }
    val cost = LongArray(n) { jin.nextLong() }
    var dpPrev = LongArray(10001) { -1 }
    for (k in 0..10000) {
        if (k <= c[0] && k.toLong() * cost[0] <= w) {
            dpPrev[k] = w - (k.toLong() * cost[0])
        }
    }
    for (j in 1 until n) {
        val dp = LongArray(10001) { -1 }
        val q = LinkedList<Int>()
        for (k in 0..10000) {
            if (dpPrev[k] >= 0L) {
                dpPrev[k] = min(w + (k.toLong() * b), dpPrev[k] + x) + (k.toLong() * cost[j])
                while (q.isNotEmpty() && dpPrev[q[0]] <= dpPrev[k]) {
                    q.removeFirst()
                }
                q.addFirst(k)
            }
            if (q.last < k - c[j]) {
                q.removeLast()
                if (q.isEmpty()) {
                    break
                }
            }
            dp[k] = dpPrev[q.last] - (k.toLong() * cost[j])
        }
        dpPrev = dp
    }
    for (answer in 10000 downTo 0) {
        if (dpPrev[answer] >= 0L) {
            println(answer)
            break
        }
    }
}