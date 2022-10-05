fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 2..n) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        val best1 = IntArray(n + 1)
        val best2 = IntArray(n + 1)
        fun recur1(a: Int, parent: Int): Pair<Int, Int> {
            var sum = 0
            var d1 = 0
            var d2 = 0
            for (b in adj[a]) {
                if (b != parent) {
                    val (x, y) = recur1(b, a)
                    sum += y + 1
                    if (x - y - 1 < d1) {
                        best2[a] = best1[a]
                        best1[a] = b
                        d2 = d1
                        d1 = x - y - 1
                    } else if (x - y - 1 < d2) {
                        d2 = x - y - 1
                        best2[a] = b
                    }
                }
            }
            return Pair(sum + d1, sum + d1 + d2)
        }
        recur1(1, 0)
        val remove = mutableListOf<Pair<Int, Int>>()
        val lines = mutableListOf<Pair<Int, Int>>()
        fun recur2(a: Int, parent: Int, type: Int): Int? {
            val connect = listOf(best1[a], if (type == 2) best2[a] else 0).filter { it != 0 }
            val leaves = mutableListOf<Int>()
            for (b in adj[a]) {
                if (b != parent) {
                    if (b in connect) {
                        leaves.add(recur2(b, a, 1)!!)
                    } else {
                        remove.add(Pair(a, b))
                        recur2(b, a, 2)
                    }
                }
            }
            while (leaves.size <= type) {
                leaves.add(a)
            }
            return if (type == 1) {
                leaves[0]
            } else {
                lines.add(Pair(leaves[0], leaves[1]))
                null
            }
        }
        recur2(1, 0, 2)
        println(remove.size)
        for (j in remove.indices) {
            println("${remove[j].first} ${remove[j].second} ${lines[j].second} ${lines[j + 1].first}")
        }
    }
}