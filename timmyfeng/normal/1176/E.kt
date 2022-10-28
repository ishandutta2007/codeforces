import java.io.*

fun main() {
	val cin = System.`in`.bufferedReader()
	val cout = PrintWriter(System.out, false)

	var t = cin.readLine().toInt()
	while (t-- > 0) {
		val (n, m) = cin.readLine().split(" ").map {it.toInt()}

		val adj = Array(n) { mutableListOf<Int>() }
		for (i in 0 until m) {
			val (u, v) = cin.readLine().split(" ").map {it.toInt()}
			adj[u - 1].add(v - 1)
			adj[v - 1].add(u - 1)
		}

		val visited = BooleanArray(n)
		val color = IntArray(n)
		var white = 0

		fun dfs(u: Int) {
			visited[u] = true
			if (color[u] == 1) {
				++white
			}

			for (c in adj[u]) {
				if (!visited[c]) {
					color[c] = 1 - color[u]
					dfs(c)
				}
			}
		}
		dfs(0)

		if (white > n - white) {
			for (i in 0 until n) {
				color[i] = 1 - color[i]
			}
			white = n - white
		}

		cout.println(white)
		for (i in 0 until n) {
			if (color[i] == 1) {
				cout.print("${i + 1} ")
			}
		}
		cout.println()
	}
	cout.close()
}