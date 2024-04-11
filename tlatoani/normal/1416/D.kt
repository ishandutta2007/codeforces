import java.io.BufferedInputStream
import java.util.*
import kotlin.math.max

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val m = jin.nextInt()
    val q = jin.nextInt()
    val p = IntArray(n + 1)
    for (j in 1..n) {
        p[j] = jin.nextInt()
    }
    val edges = Array(m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        Edge(p[a], p[b])
    }
    val queries = Array(q) {
        val type = jin.nextInt()
        val param = jin.nextInt()
        if (type == 2) {
            edges[param - 1].removal = it
        }
        Query(type, param)
    }
    edges.sortByDescending { it.removal }
    val union = IntArray(n + 1) { it }
    val rank = IntArray(n + 1) { 1 }
    fun getUnion(u: Int): Int {
        if (union[u] != union[union[u]]) {
            union[u] = getUnion(union[u])
        }
        return union[u]
    }
    val children = Array(n + 1) { mutableListOf<Int>() }
    for (edge in edges) {
        val u = getUnion(edge.a)
        val v = getUnion(edge.b)
        if (u != v) {
            if (rank[u] > rank[v]) {
                children[u].add(v)
                union[v] = u
                rank[u] += rank[v]
                if (edge.removal < q) {
                    queries[edge.removal].child = v
                }
            } else {
                children[v].add(u)
                union[u] = v
                rank[v] += rank[u]
                if (edge.removal < q) {
                    queries[edge.removal].child = u
                }
            }
        }
    }
    val l = IntArray(n + 1)
    var currL = 1
    fun recur(a: Int) {
        l[a] = currL
        currL++
        for (b in children[a]) {
            recur(b)
        }
    }
    val treeSet = TreeSet<Int>()
    for (a in 1..n) {
        if (l[a] == 0) {
            treeSet.add(currL)
            recur(getUnion(a))
        }
    }
    treeSet.add(n + 1)
    val segTree = MaxSegmentTree(1, n)
    for (a in 1..n) {
        segTree[l[a]] = a
    }
    val out = StringBuilder()
    for (query in queries) {
        if (query.type == 1) {
            val a = p[query.param]
            val res = segTree[treeSet.floor(l[a])!!, treeSet.higher(l[a])!! - 1]
            //println("type 1 for $a -> ${Pair(treeSet.floor(l[a])!!, treeSet.higher(l[a])!! - 1)} => $res")
            out.appendln(res)
            if (res != 0) {
                segTree[l[res]] = 0
            }
        } else {
            //println("bonk ${queries[j].child}")
            if (query.child != 0) {
                treeSet.add(l[query.child])
            }
        }
    }
    print(out)
}

class Edge(val a: Int, val b: Int) {
    var removal = 115115115
}

class Query(val type: Int, val param: Int) {
    var child = 0
}

class MaxSegmentTree(val treeFrom: Int, treeTo: Int) {
    val value: IntArray
    val length: Int

    init {
        var e = 0
        while (1 shl e < treeTo - treeFrom + 1) {
            e++
        }
        value = IntArray(1 shl (e + 1))
        length = 1 shl e
    }

    operator fun set(index: Int, delta: Int) {
        var node = index - treeFrom + length
        value[node] = delta
        node = node shr 1
        while (node > 0) {
            value[node] = max(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromIndex: Int, toIndex: Int): Int {
        if (toIndex < fromIndex) {
            return 0
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Int = Int.MIN_VALUE
        while (from + (from and -from) <= to) {
            res = max(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = max(res, value[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
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