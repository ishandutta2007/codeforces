import java.io.BufferedInputStream
import java.util.*

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    repeat(jin.nextInt()) {
        val n = jin.nextInt()
        val adj = Array(1 shl n) { mutableListOf<Int>() }
        repeat(n * (1 shl (n - 1))) {
            val a = jin.nextInt()
            val b = jin.nextInt()
            adj[a].add(b)
            adj[b].add(a)
        }
        val position = IntArray(1 shl n)
        val dist = IntArray(1 shl n) { -1 }
        dist[0] = 0
        val q = LinkedList<Int>()
        q.add(0)
        var disp = 1
        val permutation = IntArray(1 shl n)
        while (q.isNotEmpty()) {
            val a = q.remove()
            permutation[position[a]] = a
            for (b in adj[a]) {
                if (dist[b] == -1 || dist[b] == dist[a] + 1) {
                    if (dist[b] == -1) {
                        dist[b] = dist[a] + 1
                        q.add(b)
                    }
                    if (a == 0) {
                        position[b] = disp
                        disp *= 2
                    } else {
                        position[b] = position[b] or position[a]
                    }
                }
            }
        }
        out.appendln(permutation.joinToString(" "))
        if ((1 shl n) % n == 0) {
            val coloring = IntArray(1 shl n)
            for (mask in 0 until (1 shl n)) {
                val position = (mask - (mask and 1)) + (Integer.bitCount(mask) and 1)
                var color = 0
                for (j in 1 until n) {
                    if ((mask shr j) and 1 == 1) {
                        color = color xor j
                    }
                }
                coloring[permutation[position]] = color
            }
            out.appendln(coloring.joinToString(" "))
        } else {
            out.appendln(-1)
        }
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