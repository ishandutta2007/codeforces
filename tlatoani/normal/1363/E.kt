import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    val initial = IntArray(n + 1)
    val goal = IntArray(n + 1)
    val cost = LongArray(n + 1)
    for (j in 1..n) {
        val (a, b, c) = jin.readLine().split(" ").map { it.toInt() }
        initial[j] = b
        goal[j] = c
        cost[j] = a.toLong()
    }
    for (j in 2..n) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(b)
        adj[b].add(a)
    }
    var answer = 0L
    fun recur(a: Int): Long {
        var rem0 = 0L
        var rem1 = 0L
        if (initial[a] != goal[a]) {
            when (initial[a]) {
                0 -> rem0++
                1 -> rem1++
            }
        }
        for (b in adj[a]) {
            adj[b].remove(a)
            cost[b] = min(cost[b], cost[a])
            val d = recur(b)
            if (d < 0) {
                rem0 += -d
            } else {
                rem1 += d
            }
        }
        answer += 2L * min(rem0, rem1) * cost[a]
        return rem1 - rem0
    }
    if (recur(1) == 0L) {
        println(answer)
    } else {
        println(-1)
    }
}