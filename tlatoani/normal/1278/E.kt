import java.lang.StringBuilder
import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val parent = IntArray(n + 1)
    val l = IntArray(n + 1)
    val r = IntArray(n + 1)
    val stack = Stack<Int>()
    l[1] = 1
    var k = 1
    stack.push(1)
    while (!stack.isEmpty()) {
        val a = stack.pop()
        for (b in adj[a]) {
            if (b != parent[a]) {
                parent[b] = a
                k++
                l[b] = k
            }
        }
        k++
        r[a] = k
        for (b in adj[a]) {
            if (b != parent[a]) {
                stack.push(b)
            }
        }
    }
    val out = StringBuilder()
    for (a in 1..n) {
        out.append(l[a]).append(' ').append(r[a]).append('\n')
    }
    print(out)
}