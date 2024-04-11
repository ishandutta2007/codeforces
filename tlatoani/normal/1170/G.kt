import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val builder = StringBuilder()
    var k = 0
    val degree = IntArray(n + 1)
    val adj = Array(n + 1) { mutableMapOf<Int, Int>() }
    for (i in 1..m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        if (a == b) {
            k++
            builder.append("2 ")
            builder.append(a)
            builder.append(' ')
            builder.append(b)
            builder.append('\n')
        } else {
            adj[a][b] = adj[a].getOrDefault(b, 0) + 1
            degree[a]++
            adj[b][a] = adj[b].getOrDefault(a, 0) + 1
            degree[b]++
        }
    }
    for (d in degree) {
        if (d % 2 == 1) {
            println("NO")
            return
        }
    }
    for (root in 1..n) {
        val stack = Stack<Int>()
        val visited = mutableSetOf<Int>()
        var next = root
        while (true) {
            if (visited.contains(next)) {
                k++
                val cycle = Stack<Int>()
                cycle.push(next)
                while (stack.peek() != next) {
                    val node = stack.pop()
                    visited.remove(node)
                    cycle.push(node)
                }
                cycle.push(next)
                builder.append(cycle.size)
                while (!cycle.isEmpty()) {
                    builder.append(' ')
                    builder.append(cycle.pop())
                }
                builder.append('\n')
            } else {
                stack.push(next)
                visited.add(next)
            }
            if (adj[next].isEmpty()) {
                break
            } else {
                val prev = next
                next = adj[prev].entries.first().key
                if (adj[prev][next]!! == 1) {
                    adj[prev].remove(next)
                    adj[next].remove(prev)
                } else {
                    adj[prev][next] = adj[prev][next]!! - 1
                    adj[next][prev] = adj[prev][next]!!
                }
            }
        }
    }
    println("YES")
    println(k)
    print(builder)
}