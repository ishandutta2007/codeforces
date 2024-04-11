import java.util.*

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val actualAdj = Array(n + 1) { mutableSetOf<Int>() }
        repeat(m) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            actualAdj[a].add(b)
            actualAdj[b].add(a)
        }
        val adj = Array(n + 1) { mutableSetOf<Int>() }
        val components = LinkedList<MutableList<Int>>()
        for (a in 1..n) {
            var newComponent = mutableListOf(a)
            repeat(components.size) {
                val component = components.removeFirst()
                var found = false
                for (b in component) {
                    if (b !in actualAdj[a]) {
                        adj[a].add(b)
                        adj[b].add(a)
                        found = true
                        break
                    }
                }
                if (found) {
                    if (component.size > newComponent.size) {
                        component.addAll(newComponent)
                        newComponent = component
                    } else {
                        newComponent.addAll(component)
                    }
                } else {
                    components.addLast(component)
                }
            }
            components.addLast(newComponent)
        }
        val stack = Stack<Int>()
        for (a in 1..n) {
            if (adj[a].size <= 1) {
                stack.push(a)
            }
        }
        val seen = BooleanArray(n + 1)
        val p = IntArray(n + 1)
        val q = IntArray(n + 1)
        var k = 0
        while (stack.isNotEmpty()) {
            val a = stack.pop()
            if (!seen[a]) {
                k++
                if (adj[a].isEmpty()) {
                    p[a] = k
                    q[a] = k
                } else {
                    val b = adj[a].toList().first()
                    q[b] = k
                    seen[b] = true
                    for (c in adj[b]) {
                        if (adj[c].size == 1) {
                            p[c] = k
                            k++
                            q[c] = k
                            seen[c] = true
                        } else {
                            adj[c].remove(b)
                            if (adj[c].size == 1) {
                                stack.push(c)
                            }
                        }
                    }
                    p[b] = k
                }
            }
        }
        out.appendln(p.toList().subList(1, n + 1).joinToString(" "))
        out.appendln(q.toList().subList(1, n + 1).joinToString(" "))
    }
    print(out)
}