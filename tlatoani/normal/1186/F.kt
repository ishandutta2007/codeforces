import java.io.BufferedInputStream
import java.util.*

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val m = jin.nextInt()
    val adj = Array(n + 1) { LinkedList<Edge>() }
    for (j in 1..m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        adj[a].add(Edge(b, j))
        adj[b].add(Edge(a, j))
    }
    val used = BooleanArray(m + 1)
    var k = 0
    val out = StringBuilder()
    var r = 1
    while (r <= n) {
        val path = mutableListOf(r)
        var a = r
        while (true) {
            while (adj[a].isNotEmpty() && used[adj[a][0].ix]) {
                adj[a].removeFirst()
            }
            if (adj[a].isEmpty()) {
                break
            }
            val (b, j) = adj[a][0]
            adj[a].removeFirst()
            used[j] = true
            path.add(b)
            a = b
        }
        path.reverse()
        a = r
        while (true) {
            while (adj[a].isNotEmpty() && used[adj[a][0].ix]) {
                adj[a].removeFirst()
            }
            if (adj[a].isEmpty()) {
                break
            }
            val (b, j) = adj[a][0]
            adj[a].removeFirst()
            used[j] = true
            path.add(b)
            a = b
        }
        if (path.size == 1) {
            r++
        } else {
            for (j in 0..path.size - 2 step 2) {
                k++
                out.append(path[j]).append(' ').appendln(path[j + 1])
            }
            if (path.size % 2 == 1 && path[0] != path.last()) {
                k++
                out.append(path[path.size - 2]).append(' ').appendln(path.last())
            }
        }
    }
    println(k)
    print(out)
}

data class Edge(val to: Int, val ix: Int)

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