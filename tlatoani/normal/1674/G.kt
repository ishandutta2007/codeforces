import java.util.*
import kotlin.math.max

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    val rev = Array(n + 1) { mutableSetOf<Int>() }
    repeat(m) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        adj[a].add(b)
        rev[b].add(a)
    }
    val removeIn = (1..n).filter { rev[it].size == 1 }
    val removeOut = (1..n).filter { adj[it].size == 1 }
    for (a in removeIn) {
        if (rev[a].isNotEmpty()) {
            adj[rev[a].min()!!].remove(a)
            rev[a].clear()
        }
    }
    for (a in removeOut) {
        if (adj[a].isNotEmpty()) {
            rev[adj[a].min()!!].remove(a)
            adj[a].clear()
        }
    }
    val dp = IntArray(n + 1) { 1 }
    val stack = ArrayDeque<Int>()
    stack.addAll((1..n).filter { rev[it].isEmpty() })
    while (stack.isNotEmpty()) {
        val a = stack.pop()
        for (b in adj[a]) {
            dp[b] = max(dp[b], dp[a] + 1)
            rev[b].remove(a)
            if (rev[b].isEmpty()) {
                stack.push(b)
            }
        }
    }
    println(dp.max()!!)
}