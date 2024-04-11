import java.io.BufferedInputStream
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val l = IntArray(n + 1)
    val r = IntArray(n + 1)
    val parent = Array(19) { IntArray(n + 1) }
    val depth = IntArray(n + 1)
    var k = 0
    fun dfs1(a: Int) {
        k++
        l[a] = k
        for (b in adj[a]) {
            if (b != parent[0][a]) {
                parent[0][b] = a
                for (e in 1..18) {
                    parent[e][b] = parent[e - 1][parent[e - 1][b]]
                }
                depth[b] = depth[a] + 1
                dfs1(b)
            }
        }
        r[a] = k
    }
    dfs1(1)
    val m = jin.nextInt()
    val nodeAMT = LongArray(n + 1)
    val edgeAMT = LongArray(n + 1)
    val twoEdgeAMT = LongArray(n + 1)
    val twoEdgeFreq = mutableMapOf<TwoEdge, Long>()
    var answer = 0L
    for (j in 1..m) {
        val from = jin.nextInt()
        val to = jin.nextInt()
        var ancestor1: Int
        var ancestor2: Int
        var lca: Int
        var (a, b) = if (depth[from] < depth[to]) Pair(from, to) else Pair(to, from)
        if (a == b) {
            ancestor1 = a
            ancestor2 = b
            lca = a
        } else if (depth[a] == depth[b]) {
            for (e in 18 downTo 0) {
                if (parent[e][a] != parent[e][b]) {
                    a = parent[e][a]
                    b = parent[e][b]
                }
            }
            ancestor1 = a
            ancestor2 = b
            lca = parent[0][b]
        } else {
            for (e in 18 downTo 0) {
                if (depth[b] - depth[a] > 1 shl e) {
                    b = parent[e][b]
                }
            }
            if (parent[0][b] == a) {
                ancestor1 = a
                ancestor2 = b
                lca = a
            } else {
                b = parent[0][b]
                for (e in 18 downTo 0) {
                    if (parent[e][a] != parent[e][b]) {
                        a = parent[e][a]
                        b = parent[e][b]
                    }
                }
                ancestor1 = a
                ancestor2 = b
                lca = parent[0][b]
            }
        }
        nodeAMT[parent[0][lca]]--
        nodeAMT[lca]--
        nodeAMT[from]++
        nodeAMT[to]++
        edgeAMT[lca] -= 2L
        edgeAMT[from]++
        edgeAMT[to]++
        twoEdgeAMT[ancestor1]--
        twoEdgeAMT[ancestor2]--
        twoEdgeAMT[from]++
        twoEdgeAMT[to]++
        if (a != lca && b != lca) {
            val twoEdge = TwoEdge(min(ancestor1, ancestor2), max(ancestor1, ancestor2))
            val f = twoEdgeFreq[twoEdge] ?: 0L
            answer += f
            twoEdgeFreq[twoEdge] = f + 1L
        }
    }
    fun dfs2(a: Int) {
        for (b in adj[a]) {
            if (b != parent[0][a]) {
                dfs2(b)
                nodeAMT[a] += nodeAMT[b]
                edgeAMT[a] += edgeAMT[b]
                twoEdgeAMT[a] += twoEdgeAMT[b]
            }
        }
        answer += (nodeAMT[a] * (nodeAMT[a] - 1L)) / 2L
        answer -= edgeAMT[a] * (edgeAMT[a] - 1L)
        answer += (twoEdgeAMT[a] * (twoEdgeAMT[a] - 1L)) / 2L
    }
    dfs2(1)
    println(answer)
}

data class TwoEdge(val from: Int, val to: Int)

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
}

/*
5
1 2
1 3
1 4
3 5
5
2 3
2 4
3 4
3 5
5 1

 */