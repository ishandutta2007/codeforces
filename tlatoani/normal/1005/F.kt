import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.system.exitProcess

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, k) = jin.readLine().split(" ").map { it.toInt() }
    val adj = Array(n + 1) { mutableListOf<Edge>() }
    for (j in 0 until m) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(Edge(j, b))
        adj[b].add(Edge(j, a))
    }
    val dist = IntArray(n + 1) { -1 }
    val prev = Array(n + 1) { mutableListOf<Int>() }
    val q = LinkedList<Int>()
    dist[1] = 0
    q.add(1)
    while (q.isNotEmpty()) {
        val a = q.remove()
        for ((j, b) in adj[a]) {
            if (dist[b] == -1 || dist[a] + 1 == dist[b]) {
                prev[b].add(j)
                if (dist[b] == -1) {
                    dist[b] = dist[a] + 1
                    q.add(b)
                }
            }
        }
    }
    val out = StringBuilder()
    val option = CharArray(m) { '0' }
    var amt = 0
    fun recur(a: Int) {
        if (a > n) {
            out.appendln(option)
            amt++
            if (amt == k) {
                println(amt)
                print(out)
                exitProcess(0)
            }
        } else {
            for (j in prev[a]) {
                option[j] = '1'
                recur(a + 1)
                option[j] = '0'
            }
        }
    }
    recur(2)
    println(amt)
    print(out)
}

data class Edge(val ix: Int, val to: Int)