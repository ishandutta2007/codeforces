fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val adj = Array(n) { mutableListOf<Int>() }
        for (j in 2..n) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        val parent = Array(2) { IntArray(n) }
        val depth = Array(2) { IntArray(n) { -1 } }
        val subtree = Array(2) { LongArray(n) { 1L } }
        fun recur(r: Int, a: Int) {
            for (b in adj[a]) {
                if (depth[r][b] == -1) {
                    parent[r][b] = a
                    depth[r][b] = depth[r][a] + 1
                    recur(r, b)
                    subtree[r][a] += subtree[r][b]
                }
            }
        }
        depth[0][0] = 0
        recur(0, 0)
        depth[1][1] = 0
        recur(1, 1)
        //println(subtree[0].contentToString())
        var left = 0
        var right = 1
        var leftAMT = 0L
        var rightAMT = 0L
        val fine = BooleanArray(n)
        for (a in 0 until n) {
            if (depth[1][a] == depth[1][0] + depth[0][a]) {
                leftAMT++
            } else if (depth[0][a] == depth[0][1] + depth[1][a]) {
                rightAMT++
            }
            if (depth[0][a] + depth[1][a] == depth[0][1]) {
                fine[a] = true
            }
        }
        //println("$leftAMT $rightAMT")
        val amts = LongArray(n + 1)
        amts[0] = (n.toLong() * (n - 1).toLong()) / 2L
        for (b in adj[0]) {
            amts[0] -= (subtree[0][b] * (subtree[0][b] - 1L)) / 2L
        }
        amts[1] = leftAMT * rightAMT
        for (a in 2 until n) {
            if (!fine[a]) {
                if (depth[0][a] < depth[1][a]) {
                    var b = a
                    while (!fine[b]) {
                        fine[b] = true
                        b = parent[0][b]
                    }
                    if (b != left) {
                        break
                    }
                    left = a
                    leftAMT = subtree[0][a]
                } else {
                    var b = a
                    while (!fine[b]) {
                        fine[b] = true
                        b = parent[1][b]
                    }
                    if (b != right) {
                        break
                    }
                    right = a
                    rightAMT = subtree[0][a]
                }
            }
            amts[a] = leftAMT * rightAMT
        }
        //println(amts.contentToString())
        val answer = LongArray(n + 1) { if (it == 0) ((n.toLong() * (n - 1).toLong()) / 2L) - amts[0] else amts[it - 1] - amts[it] }
        println(answer.joinToString(" "))
    }
}