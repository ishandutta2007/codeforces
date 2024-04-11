import java.io.BufferedInputStream
import kotlin.math.max

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    repeat(jin.nextInt()) {
        val n = jin.nextInt()
        val adj = Array(n + 1) { mutableListOf<Int>() }
        repeat(n - 1) {
            val a = jin.nextInt()
            val b = jin.nextInt()
            adj[a].add(b)
            adj[b].add(a)
        }
        val depths = IntArray(n + 1)
        val ancestors = Array(n + 1) { IntArray(19) }
        fun dfs(a: Int) {
            for (d in 1..18) {
                ancestors[a][d] = ancestors[ancestors[a][d - 1]][d - 1]
            }
            for (b in adj[a]) {
                if (b != ancestors[a][0]) {
                    depths[b] = depths[a] + 1
                    ancestors[b][0] = a
                    dfs(b)
                }
            }
        }
        dfs(1)
        fun lca(a: Int, b: Int): Int {
            if (depths[a] > depths[b]) {
                return lca(b, a)
            }
            var a = a
            var b = b
            for (d in 18 downTo 0) {
                if (depths[b] - depths[a] >= 1 shl d) {
                    b = ancestors[b][d]
                }
            }
            if (a == b) {
                return a
            }
            for (d in 18 downTo 0) {
                if (ancestors[a][d] != ancestors[b][d]) {
                    a = ancestors[a][d]
                    b = ancestors[b][d]
                }
            }
            return ancestors[b][0]
        }
        val maxDepth = depths.max()!!
        val neededEdgeLength = IntArray(n + 1) { n }
        var currLCA = 0
        var currDiameter = 0
        for (a in (2..n).sortedByDescending { depths[it] }) {
            if (currLCA == 0) {
                currLCA = a
            } else {
                currLCA = lca(currLCA, a)
                currDiameter = max(currDiameter, depths[a] + maxDepth - (2 * depths[currLCA]))
            }
            val goalMaxDepth = depths[a] - 1
            neededEdgeLength[goalMaxDepth] = goalMaxDepth - ((currDiameter + 1) / 2)
        }
        var possibleMaxDepth = 0
        for (edgeLength in 1..n) {
            while (neededEdgeLength[possibleMaxDepth] < edgeLength) {
                possibleMaxDepth++
            }
            out.append(possibleMaxDepth).append(' ')
        }
        out.appendln()
    }
    print(out)
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