import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

// An edge connects v1 to v2 with a capacity of cap, flow of flow.
class Edge(var v1: Int, var v2: Int, var cap: Int, var flow: Int) {
    var rev: Edge? = null
}

class Dinic(var n: Int) {
    // Queue for the top level BFS.
    var q: ArrayDeque<Int>

    // Stores the graph.
    var adj: Array<MutableList<Edge>>

    // s = source, t = sink
    var s: Int
    var t: Int

    // For BFS.
    var blocked: BooleanArray
    var dist: IntArray

    // Just adds an edge and ALSO adds it going backwards.
    fun add(v1: Int, v2: Int, cap: Int, flow: Int) {
        val e = Edge(v1, v2, cap, flow)
        val rev = Edge(v2, v1, 0, 0)
        adj[v1].add(e.also { rev.rev = it })
        adj[v2].add(rev.also { e.rev = it })
    }

    // Runs other level BFS.
    fun bfs(): Boolean {

        // Set up BFS
        q.clear()
        Arrays.fill(dist, -1)
        dist[t] = 0
        q.add(t)

        // Go backwards from sink looking for source.
        // We just care to mark distances left to the sink.
        while (!q.isEmpty()) {
            val node = q.poll()
            if (node == s) return true
            for (e in adj[node]) {
                if (e.rev!!.cap > e.rev!!.flow && dist[e.v2] == -1) {
                    dist[e.v2] = dist[node] + 1
                    q.add(e.v2)
                }
            }
        }

        // Augmenting paths exist iff we made it back to the source.
        return dist[s] != -1
    }

    // Runs inner DFS in Dinic's, from node pos with a flow of min.
    fun dfs(pos: Int, min: Int): Int {

        // Made it to the sink, we're good, return this as our max flow for the augmenting path.
        if (pos == t) return min
        var flow = 0

        // Try each edge from here.
        for (e in adj[pos]) {
            var cur = 0

            // If our destination isn't blocked and it's 1 closer to the sink and there's flow, we
            // can go this way.
            if (!blocked[e.v2] && dist[e.v2] == dist[pos] - 1 && e.cap - e.flow > 0) {

                // Recursively run dfs from here - limiting flow based on current and what's left on this edge.
                cur = dfs(e.v2, Math.min(min - flow, e.cap - e.flow))

                // Add the flow through this edge and subtract it from the reverse flow.
                e.flow += cur
                e.rev!!.flow = -e.flow

                // Add to the total flow.
                flow += cur
            }

            // No more can go through, we're good.
            if (flow == min) return flow
        }

        // mark if this node is now blocked.
        blocked[pos] = flow != min

        // This is the flow
        return flow
    }

    fun flow(): Int {
        clear()
        var ret = 0

        // Run a top level BFS.
        while (bfs()) {

            // Reset this.
            Arrays.fill(blocked, false)

            // Run multiple DFS's until there is no flow left to push through.
            ret += dfs(s, oo)
        }
        return ret
    }

    // Just resets flow through all edges to be 0.
    fun clear() {
        for (edges in adj) for (e in edges) e.flow = 0
    }

    companion object {
        const val oo = 1E9.toInt()
    }

    // Constructor.
    init {

        // s is the source, t is the sink, add these as last two nodes.
        s = n++
        t = n++

        // Everything else is empty.
        blocked = BooleanArray(n)
        dist = IntArray(n)
        q = ArrayDeque()
        adj= Array(n) { mutableListOf<Edge>() }
    }
}

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, k) = jin.readLine().split(" ").map { it.toInt() }
    val adj = Array(n + 1) { mutableListOf<ActualEdge>() }
    for (j in n until n + m) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(ActualEdge(b, j))
        adj[b].add(ActualEdge(a, j))
    }
    val dist = IntArray(n + 1) { -1 }
    dist[1] = 0
    val q = LinkedList<Int>()
    q.add(1)
    while (q.isNotEmpty()) {
        val a = q.remove()
        for ((b) in adj[a]) {
            if (dist[b] == -1) {
                dist[b] = dist[a] + 1
                q.add(b)
            }
        }
    }
    val dinic = Dinic(n + m)
    for (a in 1..n) {
        if (dist[a] % 2 == 0) {
            for ((b, j) in adj[a]) {
                if (dist[b] < dist[a]) {
                    dinic.add(a - 1, j, 1, 0)
                    dinic.add(b - 1, j, 1, 0)
                    dinic.add(j, n + m + 1, 1, 0)
                } else if (dist[b] > dist[a]) {
                    dinic.add(n + m, j, 1, 0)
                    dinic.add(j, a - 1, 1, 0)
                    dinic.add(j, b - 1, 1, 0)
                }
            }
        }
    }
    println(min(k, dinic.flow()))
}

data class ActualEdge(val to: Int, val index: Int)