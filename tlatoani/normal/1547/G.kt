import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(m) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
        }
        val answer = IntArray(n + 1)
        val rightNow = IntArray(n + 1)
        fun dfs(a: Int, x: Int) {
            var x = x
            if (rightNow[a] > 0) {
                x = 3
            } else if (answer[a] == 1) {
                x = max(x, 2)
            }
            if (answer[a] < x) {
                rightNow[a]++
                answer[a] = x
                for (b in adj[a]) {
                    dfs(b, x)
                }
                rightNow[a]--
            }
        }
        dfs(1, 1)
        println(answer.map { if (it == 3) -1 else it }.subList(1, n + 1).joinToString(" "))
    }
}