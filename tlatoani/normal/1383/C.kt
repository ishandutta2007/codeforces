import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    cases@for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val a = jin.readLine()
        val b = jin.readLine()
        val adj = Array(20) { mutableSetOf<Int>() }
        val forward = IntArray(20)
        for (j in 0 until n) {
            if (a[j] != b[j]) {
                val x = a[j] - 'a'
                val y = b[j] - 'a'
                adj[x].add(y)
                adj[y].add(x)
                forward[x] = forward[x] or (1 shl y)
            }
        }
        var answer = 20
        val seen = BooleanArray(20)
        val stack = Stack<Int>()
        for (r in 0..19) {
            if (!seen[r]) {
                answer--
                seen[r] = true
                stack.push(r)
                while (stack.isNotEmpty()) {
                    val x = stack.pop()
                    for (y in adj[x]) {
                        if (!seen[y]) {
                            seen[y] = true
                            stack.push(y)
                        }
                    }
                }
            }
        }
        val dp = IntArray(1 shl 20) { 115115 }
        dp[0] = 0
        for (mask in 1 until (1 shl 20)) {
            for (x in 0..19) {
                if ((mask shr x) and 1 == 1) {
                    dp[mask] = min(dp[mask], dp[mask - (1 shl x)] + if (mask and forward[x] == 0) 0 else 1)
                }
            }
        }
        answer += dp.last()
        println(answer)
    }
}