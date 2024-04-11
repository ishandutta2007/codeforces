fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val ay = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(b)
            adj[b].add(a)
        }
        val x = ay.reduce { x, y -> x xor y }
        if (x == 0) {
            println("yEs")
        } else if (k == 2) {
            println("nO")
        } else {
            var amt = 0
            fun dfs(a: Int, parent: Int): Int {
                var here = ay[a]
                for (b in adj[a]) {
                    if (b != parent) {
                        here = here xor dfs(b, a)
                    }
                }
                if (here == x) {
                    amt++
                    return 0
                } else {
                    return here
                }
            }
            dfs(1, 0)
            if (amt >= 2) {
                println("yEs")
            } else {
                println("nO")
            }
        }
    }
}