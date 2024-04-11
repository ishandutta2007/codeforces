import java.io.BufferedInputStream
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val isPrime = BooleanArray(1000002) { it >= 2 }
    for (p in 2..1000001) {
        if (isPrime[p]) {
            for (k in 2 * p..1000001 step p) {
                isPrime[k] = false
            }
        }
    }
    val jin = FastScanner()
    val n = jin.nextInt()
    val q = jin.nextInt()
    val value = IntArray(n + 1)
    val present = IntArray(1000002)
    for (j in 1..n) {
        value[j] = jin.nextInt()
        present[value[j]] = j
    }
    val union = IntArray(n + 1) { it }
    fun find(u: Int): Int {
        if (union[u] != union[union[u]]) {
            union[u] = find(union[u])
        }
        return union[u]
    }
    val root = IntArray(1000002)
    for (p in 2..1000001) {
        if (isPrime[p]) {
            for (k in p..1000001 step p) {
                if (present[k] != 0) {
                    if (root[p] == 0) {
                        root[p] = find(present[k])
                    } else {
                        union[find(present[k])] = root[p]
                    }
                }
            }
        }
    }
    for (j in 1..n) {
        present[value[j]] = find(j)
    }
    val there = Array(1000002) { ArrayDeque<Int>() }
    for (j in 1..n) {
        there[value[j] + 1].add(find(j))
    }
    for (p in 2..1000001) {
        if (root[p] != 0) {
            root[p] = find(root[p])
            for (k in p..1000001 step p) {
                if (present[k - 1] != 0) {
                    there[k].add(root[p])
                }
            }
        }
    }
    val disp = Array(n + 1) { mutableSetOf<Int>() }
    for (k in 2..1000001) {
        for (a in there[k]) {
            for (b in there[k]) {
                if (a < b) {
                    disp[a].add(b)
                }
            }
        }
    }
    val out = StringBuilder()
    repeat(q) {
        val from = jin.nextInt()
        val to = jin.nextInt()
        val u = find(from)
        val v = find(to)
        if (u == v) {
            out.appendln(0)
        } else if (max(u, v) in disp[min(u, v)]) {
            out.appendln(1)
        } else {
            out.appendln(2)
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