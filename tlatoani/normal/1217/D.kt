import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    val color = IntArray(m)
    for (j in 0 until m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        adj[a].add(b)
        color[j] = if (a < b) 1 else 2
    }
    var cyclic = false
    val stack = Stack<Int>()
    for (r in 1..n) {
        val visited = BooleanArray(n + 1)
        visited[r] = true
        stack.push(r)
        while (stack.isNotEmpty()) {
            val a = stack.pop()
            for (b in adj[a]) {
                if (b == r) {
                    cyclic = true
                }
                if (!visited[b]) {
                    visited[b] = true
                    stack.push(b)
                }
            }
        }
    }
    if (cyclic) {
        println(2)
        println(color.joinToString(" "))
    } else {
        println(1)
        println((0 until m).map { 1 }.joinToString(" "))
    }
}