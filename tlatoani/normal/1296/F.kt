import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(n + 1) { mutableMapOf<Int, Int>() }
    for (j in 0 until n - 1) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        adj[a][b] = j
        adj[b][a] = j
    }
    val parent = IntArray(n + 1)
    val parentEdge = IntArray(n + 1)
    val depth = IntArray(n + 1)
    val stack = Stack<Int>()
    stack.push(1)
    while (stack.isNotEmpty()) {
        val a = stack.pop()
        for ((b, j) in adj[a]) {
            if (b != parent[a]) {
                parent[b] = a
                parentEdge[b] = j
                depth[b] = depth[a] + 1
                stack.push(b)
            }
        }
    }
    val m = jin.readLine().toInt()
    val passengers = Array(m) {
        val tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        val g = tokenizer.nextToken().toInt()
        Passenger(a, b, g)
    }
    passengers.sortByDescending { it.g }
    val answer = IntArray(n - 1) { 1 }
    for (passenger in passengers) {
        var satisfied = false
        var a = passenger.a
        var b = passenger.b
        if (depth[a] > depth[b]) {
            val c = a
            a = b
            b = c
        }
        while (depth[b] > depth[a]) {
            answer[parentEdge[b]] = max(answer[parentEdge[b]], passenger.g)
            if (answer[parentEdge[b]] == passenger.g) {
                satisfied = true
            }
            b = parent[b]
        }
        while (b != a) {
            answer[parentEdge[b]] = max(answer[parentEdge[b]], passenger.g)
            if (answer[parentEdge[b]] == passenger.g) {
                satisfied = true
            }
            b = parent[b]
            answer[parentEdge[a]] = max(answer[parentEdge[a]], passenger.g)
            if (answer[parentEdge[a]] == passenger.g) {
                satisfied = true
            }
            a = parent[a]
        }
        if (!satisfied) {
            println(-1)
            return
        }
    }
    println(answer.joinToString(" "))
}

data class Passenger(val a: Int, val b: Int, val g: Int)