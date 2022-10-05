import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(b)
        adj[b].add(a)
    }
    val desiredTopic = ("0 " + jin.readLine()).split(" ").map { it.toInt() }
    val actualTopic = IntArray(n + 1) { 1 }
    val blogs = (1..n).sortedBy { desiredTopic[it] }
    for (b in blogs) {
        if (actualTopic[b] != desiredTopic[b]) {
            println(-1)
            return
        }
        for (a in adj[b]) {
            if (actualTopic[a] == actualTopic[b]) {
                actualTopic[a]++
            }
        }
    }
    println(blogs.joinToString(" "))
}