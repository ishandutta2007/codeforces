import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    val adj = Array(n + 1) { mutableListOf<Edge>() }
    val edges = Array(m) {
        val line = jin.readLine().split(" ")
        val res = Edge(line[0].toInt(), line[1].toInt(), line[2].toInt())
        adj[res.from].add(res)
        res
    }
    fun topologicalSort(cost: Int): IntArray? {
        val visited = IntArray(n + 1)
        val topological = mutableListOf<Int>()
        fun recur(a: Int): Boolean {
            if (visited[a] == 2) {
                return true
            } else if (visited[a] == 1) {
                return false
            } else {
                visited[a] = 1
                for (edge in adj[a]) {
                    if (edge.cost > cost) {
                        if (!recur(edge.to)) {
                            return false
                        }
                    }
                }
                visited[a] = 2
                topological.add(a)
                return true
            }
        }
        for (a in 1..n) {
            if (!recur(a)) {
                return null
            }
        }
        val res = IntArray(n + 1)
        for (j in 0 until n) {
            res[topological[j]] = j
        }
        return res
    }
    var upper = 1000000000
    var lower = 0
    while (upper > lower) {
        val mid = (upper + lower) / 2
        if (topologicalSort(mid) == null) {
            lower = mid + 1
        } else {
            upper = mid
        }
    }
    val topological = topologicalSort(upper)!!
    val answer = mutableListOf<Int>()
    for (j in 1..m) {
        if (topological[edges[j - 1].from] < topological[edges[j - 1].to]) {
            answer.add(j)
        }
    }
    println("$upper ${answer.size}")
    println(answer.joinToString(" "))
}

data class Edge(val from: Int, val to: Int, val cost: Int)