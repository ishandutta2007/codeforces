import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val k = jin.nextInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (i in 1..k) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    var happy = 0
    val visited = BooleanArray(n + 1) { false }
    for (root in 1..n) {
        if (!visited[root] && adj[root].isNotEmpty()) {
            visited[root] = true
            var amtSeen = 0
            val stack = Stack<Int>()
            stack.push(root)
            while (!stack.isEmpty()) {
                val node = stack.pop()
                amtSeen++
                for (next in adj[node]) {
                    if (!visited[next]) {
                        visited[next] = true
                        stack.push(next)
                    }
                }
            }
            happy += amtSeen - 1
        }
    }
    println(k - happy)
}