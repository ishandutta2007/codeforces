import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 0 until m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val curr = mutableSetOf<Int>()
    for (j in 1..n) {
        var parent = 0
        val toRemove = mutableListOf<Int>()
        for (k in curr) {
            if (!adj[k].contains(j)) {
                if (parent == 0) {
                    parent = k
                    adj[k].retainAll(adj[j])
                } else {
                    adj[parent].retainAll(adj[k])
                    toRemove.add(k)
                }
            }
        }
        for (k in toRemove) {
            curr.remove(k)
        }
        if (parent == 0) {
            curr.add(j)
        }
    }
    println(curr.size - 1)
}