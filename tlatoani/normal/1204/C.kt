import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    jin.nextLine()
    val adj = Array(n) { jin.nextLine().let { s -> (0 until n).filter { i -> s[i] == '1' } } }
    val minDist = Array(n) { root ->
        val res = IntArray(n) { 115 }
        res[root] = 0
        val q = LinkedList<Int>()
        q.add(root)
        while (!q.isEmpty()) {
            val node = q.remove()
            for (next in adj[node]) {
                if (res[next] == 115) {
                    res[next] = res[node] + 1
                    q.add(next)
                }
            }
        }
        res
    }
    val m = jin.nextInt()
    val path = Array(m) { jin.nextInt() - 1 }
    val dp = IntArray(m)
    val prev = IntArray(m)
    val lastAppearance = IntArray(n) { -1 }
    lastAppearance[path[0]] = 0
    dp[0] = 1
    prev[0] = -1
    for (i in 1 until m) {
        prev[i] = i - 1
        lastAppearance[path[i]] = i
        for (j in lastAppearance) {
            if (j != -1 && j != i && minDist[path[j]][path[i]] == i - j && dp[j] < dp[prev[i]]) {
                prev[i] = j
            }
        }
        dp[i] = dp[prev[i]] + 1
    }
    println(dp.last())
    val answer = mutableListOf<Int>()
    var i = m - 1
    while (i != -1) {
        answer += path[i] + 1
        i = prev[i]
    }
    println(answer.reversed().joinToString(" ", "", ""))
}