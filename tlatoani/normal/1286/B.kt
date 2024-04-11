import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val parent = IntArray(n + 1)
    val children = Array(n + 1) { LinkedList<Int>() }
    val c = IntArray(n + 1)
    for (j in 1..n) {
        parent[j] = jin.nextInt()
        c[j] = jin.nextInt()
        children[parent[j]].add(j)
    }
    val answer = IntArray(n)
    for (j in 1..n) {
        var node = children[0].first
        while (c[node] > 0) {
            if (children[node].isEmpty()) {
                println("NO")
                return
            }
            c[node]--
            node = children[node].first
        }
        answer[node - 1] = j
        children[parent[node]].removeFirst()
        for (k in children[node].reversed()) {
            parent[k] = parent[node]
            children[parent[node]].addFirst(k)
        }
    }
    println("YES")
    println(answer.joinToString(" "))
}