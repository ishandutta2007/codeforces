const val MOD = 998244353L

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        val dp = (listOf(0L) + readLine()!!.split(" ").map { it.toLong() }).toLongArray()
        val inDegree = IntArray(n + 1)
        repeat(m) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            inDegree[b]++
        }
        val order = mutableListOf<Int>()
        order.addAll((1..n).filter { inDegree[it] == 0 })
        for (j in 0 until n) {
            val a = order[j]
            for (b in adj[a]) {
                inDegree[b]--
                if (inDegree[b] == 0) {
                    order.add(b)
                }
            }
        }
        order.reverse()
        var answer = 0L
        for (j in 0 until n) {
            if (dp.all { it == 0L }) {
                break
            }
            answer++
            for (a in order) {
                if (dp[a] > 0L) {
                    dp[a]--
                    for (b in adj[a]) {
                        dp[b]++
                    }
                }
            }
        }
        for (a in order.reversed()) {
            dp[a] %= MOD
            for (b in adj[a]) {
                dp[b] += dp[a]
            }
        }
        println((answer + dp[order.first()]) % MOD)
    }
}