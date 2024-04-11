import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    var tokenizer = StringTokenizer(jin.readLine())
    val dp1 = intArrayOf(0) + IntArray(n) { (2 * tokenizer.nextToken().toInt()) - 1 }
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val stack = Stack<Int>()
    val parent = IntArray(n + 1)
    stack.push(-1)
    while (stack.isNotEmpty()) {
        var a = stack.pop()
        if (a < 0) {
            a *= -1
            stack.push(a)
            for (b in adj[a]) {
                parent[b] = a
                adj[b].remove(a)
                stack.push(-b)
            }
        } else {
            if (dp1[a] > 0) {
                dp1[parent[a]] += dp1[a]
            }
        }
    }
    val dp2 = IntArray(n + 1)
    stack.push(1)
    while (stack.isNotEmpty()) {
        val a = stack.pop()
        if (a != 1) {
            dp2[a] = max(0, dp1[parent[a]] - max(0, dp1[a]) + dp2[parent[a]])
        }
        stack.addAll(adj[a])
    }
    println((1..n).map { dp1[it] + dp2[it] }.joinToString(" "))
}