import java.io.BufferedInputStream
import java.util.*

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val m = jin.nextInt()
        val adj = Array(n + 1) { ArrayDeque<Int>(4) }
        for (j in 1..m) {
            val a = jin.nextInt()
            val b = jin.nextInt()
            adj[a].add(b)
            adj[b].add(a)
        }
        val seen = IntArray(n + 1)
        val answer = mutableListOf<Int>()
        fun recur(a: Int) {
            if (seen[a] == 1) {
                answer.add(a)
                val next = mutableListOf<Int>()
                for (b in adj[a]) {
                    if (seen[b] == 0) {
                        seen[b] = -1
                        next.add(b)
                    }
                }
                for (b in next) {
                    recur(b)
                }
            } else {
                for (b in adj[a]) {
                    if (seen[b] == 0) {
                        seen[b] = 1
                        recur(b)
                    }
                }
            }
        }
        recur(1)
        seen[0] = 2
        if (seen.all { it != 0 }) {
            out.appendln("YES").appendln(answer.size).appendln(answer.joinToString(" "))
        } else {
            out.appendln("NO")
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