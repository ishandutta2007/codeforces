const val MOD = 1000000007L

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        if (k == 2) {
            println((n * (n - 1)) / 2)
        } else {
            var answer = 0L
            for (r in 1..n) {
                val byDepth = Array(n + 1) { IntArray(n) }
                fun dfs(a: Int, parent: Int, d: Int) {
                    byDepth[a][d]++
                    for (b in adj[a]) {
                        if (b != parent) {
                            dfs(b, a, d + 1)
                            for (e in d + 1 until n) {
                                byDepth[a][e] += byDepth[b][e]
                            }
                        }
                    }
                }
                dfs(r, 0, 0)
                for (d in 1 until n) {
                    val dp = LongArray(k + 1)
                    dp[0] = 1L
                    for (b in adj[r]) {
                        if (byDepth[b][d] != 0) {
                            val amt = byDepth[b][d].toLong()
                            for (x in k downTo 1) {
                                dp[x] += amt * dp[x - 1]
                                dp[x] %= MOD
                            }
                        }
                    }
                    answer += dp[k]
                    answer %= MOD
                }
            }
            println(answer)
        }
    }
}