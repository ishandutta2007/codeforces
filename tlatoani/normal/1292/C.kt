import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val y = Array(n + 1) { IntArray(n + 1) }
    val p = Array(n + 1) { IntArray(n + 1) }
    val bfs = ArrayList<Int>(n)
    val depth = IntArray(n + 1)
    for (r in 1..n) {
        depth[r] = 0
        bfs.clear()
        bfs.add(r)
        for (j in 0 until n) {
            val a = bfs[j]
            for (b in adj[a]) {
                if (b != p[r][a]) {
                    p[r][b] = a
                    depth[b] = depth[a] + 1
                    bfs.add(b)
                }
            }
        }
        for (a in bfs.reversed()) {
            y[r][a]++
            y[r][p[r][a]] += y[r][a]
        }
    }
    var answer = 0L
    val dp = Array(n + 1) { LongArray(n + 1) }
    fun evalDP(a: Int, b: Int): Long {
        if (dp[a][b] == 0L) {
            if (p[a][b] != a) {
                dp[a][b] = max(evalDP(a, p[a][b]), evalDP(p[b][a], b))
            }
            dp[a][b] += (y[b][a] * y[a][b]).toLong()
            dp[b][a] = dp[a][b]
        }
        return dp[a][b]
    }
    for (a in 1..n) {
        for (b in a + 1..n) {
            answer = max(answer, evalDP(a, b))
        }
    }
    println(answer)
}