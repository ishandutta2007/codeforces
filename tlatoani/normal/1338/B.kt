import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    var r = 0
    for (j in 2..n) {
        val tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        adj[a].add(b)
        adj[b].add(a)
        if (adj[a].size > 1) {
            r = a
        } else if (adj[b].size > 1) {
            r = b
        }
    }
    var mexico = n - 1
    for (a in 1..n) {
        var leaves = 0
        for (b in adj[a]) {
            if (adj[b].size == 1) {
                leaves++
            }
        }
        mexico -= max(0, leaves - 1)
    }
    var depth = IntArray(n + 1)
    val stack = Stack<Int>()
    stack.push(r)
    var parity = -1
    while (stack.isNotEmpty()) {
        val a = stack.pop()
        for (b in adj[a]) {
            adj[b].remove(a)
            depth[b] = depth[a] + 1
            stack.push(b)
        }
        if (adj[a].size == 0) {
            if (parity == -1) {
                parity = depth[a] % 2
            } else if (parity != -2 && parity != depth[a] % 2) {
                parity = -2
            }
        }
    }
    val minimo = if (parity == -2) 3 else 1
    println("$minimo $mexico")
}