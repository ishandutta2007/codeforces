import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val k = jin.nextInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    val edges = mutableMapOf<Pair<Int, Int>, Int>()
    for (i in 1 until n) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        adj[a].add(b)
        adj[b].add(a)
        edges[Pair(a, b)] = i
        edges[Pair(b, a)] = i
    }
    val bfs = mutableListOf<Int>()
    val parent = IntArray(n + 1)
    bfs += 1
    for (i in 0 until n) {
        for (child in adj[bfs[i]]) {
            parent[child] = bfs[i]
            adj[child].remove(bfs[i])
            bfs += child
        }
    }
    val dp = Array(n + 1) { Array<DP?>(n + 1) { null } }
    var answer = Int.MAX_VALUE
    var answerNode = -1
    var answerDP = DP(0, 0, -1, null)
    for (node in bfs.reversed()) {
        dp[node][1] = DP(0, 0, -1, null)
        for (child in adj[node]) {
            val next = Array(n + 1) { i -> dp[node][i]?.let { d -> DP(d.amt + 1, child, 0, d) } }
            for (a in 1..n) {
                for (b in 1..n - a) {
                    dp[node][a]?.let { d1 -> dp[child][b]?.let { d2 ->
                        if (next[a + b] == null || d1.amt + d2.amt < next[a + b]!!.amt) {
                            next[a + b] = DP(d1.amt + d2.amt, child, b, d1)
                        }
                    }}
                }
            }
            dp[node] = next
        }
        if (dp[node][k] != null && dp[node][k]!!.amt + (if (node == 1) 0 else 1) < answer) {
            answer = dp[node][k]!!.amt + if (node == 1) 0 else 1
            answerNode = node
            answerDP = dp[node][k]!!
        }
    }
    println(answer)
    val answerEdges = mutableListOf<Int>()
    if (answerNode != 1) {
        answerEdges += edges[Pair(answerNode, parent[answerNode])]!!
    }
    val stack = Stack<DP>()
    stack.push(answerDP)
    while (!stack.isEmpty()) {
        val d = stack.pop()
        //println("d = $d")
        if (d.childKey == 0) {
            answerEdges += edges[(Pair(d.child, parent[d.child]))]!!
        } else if (d.child != 0) {
            stack.push(dp[d.child][d.childKey])
        }
        if (d.rem != null) {
            stack.push(d.rem)
        }
    }
    println(answerEdges.joinToString(" ", "", ""))
}

data class DP(val amt: Int, val child: Int, val childKey: Int, val rem: DP?)