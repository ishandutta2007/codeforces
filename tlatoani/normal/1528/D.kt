import java.io.BufferedInputStream
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val m = jin.nextInt()
    val mod = IntArray(2 * n) { it % n }
    val edges = Array(n) { IntArray(n) { Int.MAX_VALUE } }
    val minCannon = IntArray(n) { Int.MAX_VALUE }
    for (j in 1..m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        val c = jin.nextInt()
        minCannon[a] = min(minCannon[a], c)
        for (d in b until n) {
            edges[a][d] = min(edges[a][d], c + (d - b))
        }
        for (d in 0 until b) {
            edges[a][d] = min(edges[a][d], c + (d - b + n))
        }
    }
    val out = StringBuilder()
    val pq = Array(n) { mutableListOf<Int>() }
    for (r in 0 until n) {
        pq.forEach { it.clear() }
        val answer = IntArray(n) { a -> edges[r][a] }
        answer[r] = 0
        for (a in 0 until n) {
            if (a != r) {
                pq[answer[a] - minCannon[r]].add(a)
            }
        }
        for (d in 0 until n) {
            for (a in pq[d]) {
                if (minCannon[r] + d == answer[a]) {
                    val x = answer[a] % n
                    for (b in 0 until n) {
                        val nd = answer[a] + edges[a][mod[b - x + n]]
                        if (nd < answer[b]) {
                            answer[b] = nd
                            pq[nd - minCannon[r]].add(b)
                        }
                    }
                }
            }
        }
        out.appendln(answer.joinToString(" "))
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