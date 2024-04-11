import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        val tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val dpWith = IntArray(n + 1)
    val dpWithout = IntArray(n + 1)
    var answer = 0
    fun recur(a: Int) {
        var with1 = 0
        var with2 = 0
        var without1 = 0
        var without2 = 0
        for (b in adj[a]) {
            adj[b].remove(a)
            recur(b)
            if (dpWithout[b] > without1) {
                without2 = without1
                without1 = dpWithout[b]
            } else if (dpWithout[b] > without2) {
                without2 = dpWithout[b]
            }
            if (dpWith[b] > with1) {
                with2 = with1
                with1 = dpWith[b]
            } else if (dpWith[b] > with2) {
                with2 = dpWith[b]
            }
        }
        dpWith[a] = without1 + 1
        dpWithout[a] = with1 + max(0, adj[a].size - 1)
        dpWith[a] = max(dpWith[a], dpWithout[a])
        var posWith = 1 + without1 + without2
        var posWithout = with1 + with2 + max(0, adj[a].size - 2) + (if (a == 1) 0 else 1)
        answer = max(answer, max(posWith, posWithout))
    }
    recur(1)
    println(answer)
}