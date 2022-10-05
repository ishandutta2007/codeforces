fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val biomes = Array(n) { readLine()!!.split(" ").map { it.toInt() } }
        val adj = Array(101) { mutableListOf<Int>() }
        fun addEdge(a: Int, b: Int) {
            if (a != 0 && b != 0) {
                adj[a].add(b)
                adj[b].add(a)
            }
        }
        val present = BooleanArray(101)
        for (y in 0 until n) {
            for (x in 0 until m) {
                if (y > 0) {
                    addEdge(biomes[y - 1][x], biomes[y][x])
                }
                if (x > 0) {
                    addEdge(biomes[y][x - 1], biomes[y][x])
                }
                present[biomes[y][x]] = true
            }
        }
        val r = (1..100).first { present[it] }
        val subtree = IntArray(101) { 1 }
        val children = Array(101) { mutableListOf<Int>() }
        fun dfs(a: Int) {
            present[a] = false
            for (b in adj[a]) {
                if (present[b]) {
                    children[a].add(b)
                    dfs(b)
                    subtree[a] += subtree[b]
                }
            }
        }
        dfs(r)
        present[0] = false
        if (present.any { it }) {
            out.appendln(-1)
        } else {
            val k = subtree[r]
            val answer = Array(k) { IntArray(k) }
            fun dfs2(a: Int, y: Int, x: Int) {
                for (j in 0 until subtree[a]) {
                    answer[y + j][x + j] = a
                }
                var j = 0
                for (b in children[a]) {
                    dfs2(b, y + 1 + j, x + j)
                    j += subtree[b]
                }
            }
            dfs2(r, 0, 0)
            for (y in 0 until k) {
                for (x in 0 until y) {
                    if (answer[y][x] == 0) {
                        answer[y][x] = answer[y - 1][x + 1]
                    }
                }
            }
            for (y in 0 until k) {
                for (x in y until k) {
                    answer[y][x] = answer[x][y]
                }
            }
            out.appendln("$k $k")
            answer.forEach { out.appendln(it.joinToString(" ")) }
        }
    }
    print(out)
}