import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val z = IntArray((2 * n) + 1)
    for (j in 1..n) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        z[line.substring(0, six).toInt()] = j
        z[line.substring(six + 1).toInt()] = -j
    }
    var edges = 0
    val list = LinkedList<Int>()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (x in 1..2 * n) {
        if (z[x] > 0) {
            list.addFirst(z[x])
        } else {
            val j = -z[x]
            val iter = list.iterator()
            var k = iter.next()
            while (k != j) {
                edges++
                if (edges >= n) {
                    println("NO")
                    return
                }
                adj[j].add(k)
                adj[k].add(j)
                k = iter.next()
            }
            iter.remove()
        }
    }
    if (edges != n - 1) {
        println("NO")
        return
    }
    val visited = BooleanArray(n + 1)
    visited[1] = true
    val stack = Stack<Int>()
    stack.push(1)
    var amtVisited = 0
    while (!stack.isEmpty()) {
        val j = stack.pop()
        amtVisited++
        for (k in adj[j]) {
            if (visited[k]) {
                println("NO")
                return
            }
            visited[k] = true
            adj[k].remove(j)
            stack.push(k)
        }
    }
    if (amtVisited < n) {
        println("NO")
        return
    }
    println("YES")
}