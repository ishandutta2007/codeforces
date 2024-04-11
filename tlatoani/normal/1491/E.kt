import java.io.BufferedInputStream
import java.util.*

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val adj = Array(n + 1) { ArrayDeque<Edge>(4) }
    for (j in 2..n) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        val edge = Edge(a, b)
        adj[a].add(edge)
        adj[b].add(edge)
    }
    val fibonacci = IntArray(28)
    fibonacci[1] = 1
    for (j in 2 until fibonacci.size) {
        fibonacci[j] = fibonacci[j - 2] + fibonacci[j - 1]
    }
    if (n !in fibonacci) {
        println("nO")
        return
    }
    fun recur(r: Int, k: Int): Boolean {
        if (k <= 2) {
            return true
        } else {
            var cutEdge = Edge(0, 0)
            var s = 0
            var t = 0
            fun dfs(a: Int, parent: Int, parentEdge: Edge): Int {
                var subtree = 1
                for (edge in adj[a]) {
                    if (edge.enabled && edge != parentEdge) {
                        val b = edge.a + edge.b - a
                        val under = dfs(b, a, edge)
                        if (under == -1) {
                            return -1
                        }
                        subtree += under
                    }
                }
                if (subtree == fibonacci[k - 1]) {
                    cutEdge = parentEdge
                    s = a
                    t = parent
                    return -1
                }
                if (subtree == fibonacci[k - 2]) {
                    cutEdge = parentEdge
                    s = parent
                    t = a
                    return -1
                }
                return subtree
            }
            dfs(r, 0, cutEdge)
            return if (s == 0) {
                false
            } else {
                cutEdge.enabled = false
                recur(s, k - 1) && recur(t, k - 2)
            }
        }
    }
    println(if (recur(1, fibonacci.indexOf(n))) "yEs" else "nO")
}

class Edge(val a: Int, val b: Int) {
    var enabled = true
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