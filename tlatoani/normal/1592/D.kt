fun main() {
    val n = readLine()!!.toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    repeat(n - 1) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        adj[a].add(b)
        adj[b].add(a)
    }
    fun query(nodes: Iterable<Int>): Int {
        println("? ${nodes.toList().size} ${nodes.joinToString(" ")}")
        return readLine()!!.toInt()
    }
    val maxDist = query(1..n)
    val parent = IntArray(n + 1)
    val order = mutableListOf<Int>()
    fun dfs(a: Int) {
        order.add(a)
        for (b in adj[a]) {
            if (b != parent[a]) {
                parent[b] = a
                dfs(b)
            }
        }
    }
    dfs(1)
    var upper = n - 1
    var lower = 1
    while (upper > lower) {
        val mid = (upper + lower) / 2
        if (query(order.subList(0, mid + 1)) == maxDist) {
            upper = mid
        } else {
            lower = mid + 1
        }
    }
    val a = order[upper]
    println("! $a ${parent[a]}")
}