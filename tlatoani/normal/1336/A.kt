import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    var k = tokenizer.nextToken().toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val parent = IntArray(n + 1)
    val subTree = IntArray(n + 1) { 1 }
    val depth = IntArray(n + 1)
    val stack = Stack<Int>()
    stack.push(1)
    val pq = PriorityQueue<Int>(compareBy { subTree[it] - depth[it] })
    while (stack.isNotEmpty()) {
        val a = stack.pop()
        for (b in adj[a]) {
            adj[b].remove(a)
            parent[b] = a
            depth[b] = depth[a] + 1
            stack.push(b)
        }
        if (adj[a].isEmpty()) {
            pq.add(a)
        }
    }
    var answer = 0L
    while (k > 0) {
        k--
        val a = pq.remove()
        answer += (depth[a] - subTree[a] + 1).toLong()
        adj[parent[a]].remove(a)
        subTree[parent[a]] += subTree[a]
        if (adj[parent[a]].isEmpty()) {
            pq.add(parent[a])
        }
    }
    println(answer)
}