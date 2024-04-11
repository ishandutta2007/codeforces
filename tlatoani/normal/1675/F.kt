fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        val things = readLine()!!.split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        val parents = IntArray(n + 1)
        val depth = IntArray(n + 1)
        fun dfs(a: Int) {
            for (b in adj[a]) {
                if (b != parents[a]) {
                    parents[b] = a
                    depth[b] = depth[a] + 1
                    dfs(b)
                }
            }
        }
        dfs(x)
        val needsToVisit = BooleanArray(n + 1)
        fun mark(a: Int) {
            if (a != x && !needsToVisit[a]) {
                needsToVisit[a] = true
                mark(parents[a])
            }
        }
        mark(y)
        for (a in things) {
            mark(a)
        }
        val answer = (2 * needsToVisit.count { it }) - depth[y]
        println(answer)
    }
}