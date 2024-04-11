import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(jin.readLine())
    val cost = longArrayOf(0L) + LongArray(n) { tokenizer.nextToken().toLong() }
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    var answer = 0L
    val stack = Stack<Int>()
    for (r in 1..n) {
        if (cost[r] != -1L) {
            var minCost = cost[r]
            cost[r] = -1L
            stack.push(r)
            while (stack.isNotEmpty()) {
                val a = stack.pop()
                for (b in adj[a]) {
                    if (cost[b] != -1L) {
                        minCost = min(minCost, cost[b])
                        cost[b] = -1L
                        stack.push(b)
                    }
                }
            }
            answer += minCost
        }
    }
    println(answer)
}