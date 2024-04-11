import java.util.*
import kotlin.math.min

fun main() {
    val (n1, n2, m) = readLine()!!.split(" ").map { it.toInt() }
    val adj = Array(n1 + n2 + 1) { mutableSetOf<Int>() }
    val people = IntArray(n1 + n2 + 1)
    val tokenizer = StringTokenizer(readLine()!!)
    for (a in 1..n1) {
        people[a] = tokenizer.nextToken().toInt()
    }
    for (a in n1 + 1..n1 + n2) {
        people[a] = 1000000
    }
    repeat(m) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        adj[a].add(n1 + b)
        adj[n1 + b].add(a)
    }
    val stack = ArrayDeque<Int>()
    val seen = BooleanArray(n1 + n2 + 1)
    for (a in 1..n1 + n2) {
        if (adj[a].size <= 1) {
            stack.push(a)
        }
    }
    var answer = 0
    while (stack.isNotEmpty()) {
        val a = stack.pop()
        if (!seen[a]) {
            seen[a] = true
            if (adj[a].isEmpty()) {
                answer += people[a]
            } else {
                val b = adj[a].first()
                people[b] = min(people[a], people[b])
                adj[b].remove(a)
                if (adj[b].size <= 1) {
                    stack.push(b)
                }
            }
        }
    }
    println(answer)
}