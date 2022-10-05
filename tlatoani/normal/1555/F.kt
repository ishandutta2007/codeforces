import java.io.BufferedInputStream

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val q = jin.nextInt()
    val edges = Array(q) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        val x = jin.nextInt()
        Edge(a, b, x)
    }
    val union = IntArray(n + 1) { it }
    fun find(u: Int): Int {
        if (union[union[u]] != union[u]) {
            union[u] = find(union[u])
        }
        return union[u]
    }
    val used = BooleanArray(q)
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for ((j, edge) in edges.withIndex()) {
        val (a, b) = edge
        if (find(a) != find(b)) {
            used[j] = true
            union[find(a)] = find(b)
            adj[a].add(b)
            adj[b].add(a)
        }
    }
    val seen = BooleanArray(n + 1)
    val l = IntArray(n + 1)
    val r = IntArray(n + 1)
    var k = 0
    val ancestors = Array(n + 1) { IntArray(19) }
    val depth = IntArray(n + 1)
    fun dfs(a: Int) {
        k++
        l[a] = k
        for (b in adj[a]) {
            if (!seen[b]) {
                seen[b] = true
                ancestors[b][0] = a
                for (d in 1..18) {
                    ancestors[b][d] = ancestors[ancestors[b][d - 1]][d - 1]
                }
                depth[b] = depth[a] + 1
                dfs(b)
            }
        }
        k++
        r[a] = k
    }
    for (a in 1..n) {
        if (!seen[a]) {
            seen[a] = true
            dfs(a)
        }
    }
    fun lca(a: Int, b: Int): Int {
        var (a, b) = if (depth[a] < depth[b]) Pair(a, b) else Pair(b, a)
        for (d in 18 downTo 0) {
            if (depth[b] - depth[a] >= 1 shl d) {
                b = ancestors[b][d]
            }
        }
        if (a == b) {
            return b
        }
        for (d in 18 downTo 0) {
            if (ancestors[a][d] != ancestors[b][d]) {
                a = ancestors[a][d]
                b = ancestors[b][d]
            }
        }
        return ancestors[a][0]
    }
    val bitPresent = BinaryIndexTree(1, 2 * n)
    val bitXOR = BinaryIndexTree(1, 2 * n)
    val out = StringBuilder()
    for ((j, edge) in edges.withIndex()) {
        val (a, b, x) = edge
        if (ancestors[a][0] == b) {
            out.appendln("YES")
            bitPresent.update(l[a], 1)
            bitPresent.update(r[a], -1)
            bitXOR.update(l[a], x)
            bitXOR.update(r[a], x)
        } else if (ancestors[b][0] == a) {
            out.appendln("YES")
            bitPresent.update(l[b], 1)
            bitPresent.update(r[b], -1)
            bitXOR.update(l[b], x)
            bitXOR.update(r[b], x)
        } else {
            val c = lca(a, b)
            if (bitPresent[l[c] + 1, l[a]] == depth[a] - depth[c] && bitPresent[l[c] + 1, l[b]] == depth[b] - depth[c] && (bitXOR[l[c] + 1, l[a]] xor bitXOR[l[c] + 1, l[b]] xor x) and 1 == 1) {
                out.appendln("YES")
                var a = a
                while (a != c) {
                    bitPresent.update(l[a], -1)
                    bitPresent.update(r[a], 1)
                    bitXOR.update(l[a], x)
                    bitXOR.update(r[a], x)
                    a = ancestors[a][0]
                }
                a = b
                while (a != c) {
                    bitPresent.update(l[a], -1)
                    bitPresent.update(r[a], 1)
                    bitXOR.update(l[a], x)
                    bitXOR.update(r[a], x)
                    a = ancestors[a][0]
                }
            } else {
                out.appendln("NO")
            }
        }
    }
    print(out)
}

data class Edge(val from: Int, val to: Int, val xor: Int)

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = IntArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Int) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Int {
        var res = 0
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            i -= i and -i
        }
        return res
    }

    operator fun get(from: Int, to: Int) = if (to < from) 0 else query(to) - query(from - 1)
}

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