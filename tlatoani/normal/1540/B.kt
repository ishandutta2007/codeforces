const val MOD = 1000000007L
val HALF = 2L pow -1

fun main() {
    val n = readLine()!!.toInt()
    val dp = Array(n + 1) { LongArray(n + 1) }
    for (x in 0..n) {
        for (y in 0..n) {
            dp[x][y] = when {
                x == 0 -> 0L
                y == 0 -> 1L
                else -> (HALF * (dp[x - 1][y] + dp[x][y - 1])) % MOD
            }
        }
    }
    val adj = Array(n + 1) { mutableListOf<Int>() }
    repeat(n - 1) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        adj[a].add(b)
        adj[b].add(a)
    }
    val dists = Array(n + 1) { IntArray(n + 1) { -1 } }
    for (r in 1..n) {
        dists[r][r] = 0
        fun dfs(a: Int) {
            for (b in adj[a]) {
                if (dists[r][b] == -1) {
                    dists[r][b] = dists[r][a] + 1
                    dfs(b)
                }
            }
        }
        dfs(r)
    }
    var answer = 0L
    for (a in 1..n) {
        for (b in a + 1..n) {
            val d = dists[a][b]
            for (r in 1..n) {
                answer += dp[(d + dists[r][a] - dists[r][b]) / 2][(d + dists[r][b] - dists[r][a]) / 2]
                answer %= MOD
            }
        }
    }
    answer *= n.toLong() pow -1
    answer %= MOD
    answer += MOD
    answer %= MOD
    println(answer)
}

const val MOD_TOTIENT = MOD.toInt() - 1

infix fun Long.pow(power: Int): Long {
    var e = power
    e %= MOD_TOTIENT
    if (e < 0) {
        e += MOD_TOTIENT
    }
    if (e == 0 && this == 0L) {
        return this
    }
    var b = this % MOD
    var res = 1L
    while (e > 0) {
        if (e and 1 != 0) {
            res *= b
            res %= MOD
        }
        b *= b
        b %= MOD
        e = e shr 1
    }
    return res
}