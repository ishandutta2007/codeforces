fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val requirements = listOf(0L, 0L) + readLine()!!.split(" ").map { it.toLong() }
        val increases = listOf(0L, 0L) + readLine()!!.split(" ").map { it.toLong() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(m) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        var upper = 1000000001L
        var lower = 0L
        while (upper > lower) {
            val mid = (upper + lower) / 2L
            var power = mid
            val reachable = mutableListOf(1)
            while (reachable.size < n) {
                val seen = BooleanArray(n + 1)
                for (a in reachable) {
                    seen[a] = true
                }
                fun dfs(a: Int, currPower: Long, prev: Int): Boolean {
                    if (seen[a]) {
                        return true
                    }
                    seen[a] = true
                    for (b in adj[a]) {
                        if (b != prev && currPower > requirements[b]) {
                            if (dfs(b, currPower + increases[b], a)) {
                                return true
                            }
                        }
                    }
                    return false
                }
                var addend = 0
                for (a in reachable) {
                    for (b in adj[a]) {
                        if (!seen[b] && power > requirements[b]) {
                            if (dfs(b, power + increases[b], a)) {
                                addend = b
                                break
                            }
                        }
                    }
                }
                if (addend == 0) {
                    break
                }
                reachable.add(addend)
                power += increases[addend]
            }
            if (reachable.size == n) {
                upper = mid
            } else {
                lower = mid + 1L
            }
        }
        println(upper)
    }
}

/*

1
4 4
11 22 13
8 7 5
1 2
2 3
3 4
4 1
4 4

 */

/*

1
7 8
1 1 1 1 6 6
1 1 1 1 1 1
1 2
2 3
3 4
4 5
5 3
1 6
6 7
7 1

 */