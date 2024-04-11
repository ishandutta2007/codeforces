import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val MOD = 1000000007L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val values = longArrayOf(0L) + LongArray(n) { tokenizer.nextToken().toLong() }
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val dp1 = Array(2) { LongArray(n + 1) }
    val stack = Stack<Int>()
    stack.push(-1)
    while (stack.isNotEmpty()) {
        var a = stack.pop()
        if (a < 0) {
            a *= -1
            stack.push(a)
            for (b in adj[a]) {
                adj[b].remove(a)
                stack.push(-b)
            }
        } else {
            dp1[0][a] = 1L
            for (s in 0..1) {
                for (b in adj[a]) {
                    dp1[s][a] += dp1[1 - s][b]
                }
            }
        }
    }
    val dp2 = Array(2) { LongArray(n + 1) }
    stack.push(1)
    var answer = 0L
    while (stack.isNotEmpty()) {
        val a = stack.pop()
        for (b in adj[a]) {
            for (s in 0..1) {
                dp2[1 - s][b] = dp1[s][a] + dp2[s][a] - dp1[1 - s][b]
            }
            stack.push(b)
        }
        var amt = 0L
        for (s in 0..1) {
            var sum1 = dp2[s][a]
            var sum2 = dp2[s][a] * dp2[s][a]
            for (b in adj[a]) {
                sum1 += dp1[1 - s][b]
                sum2 += dp1[1 - s][b] * dp1[1 - s][b]
            }
            val res = (sum1 * sum1) - sum2
            if (s == 0) {
                amt += res
            } else {
                amt -= res
            }
        }
        amt += (2L * (dp1[0][a] + dp2[0][a])) - 1L
        amt %= MOD
        answer += amt * values[a]
        answer %= MOD
    }
    println((answer + MOD) % MOD)
}