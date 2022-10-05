import java.io.BufferedInputStream
import java.util.*
import kotlin.math.max

const val BLOCK = 320

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val q = jin.nextInt()
    val parent = IntArray(n + 1)
    for (a in 2..n) {
        parent[a] = jin.nextInt()
    }
    val nextAncestor = IntArray(n + 1)
    parent[1] = 1
    nextAncestor[1] = 1
    val rem = IntArray(n + 1)
    val delta = IntArray((n / BLOCK) + 1)
    for (a in 2..n) {
        if (parent[a] / BLOCK == a / BLOCK) {
            nextAncestor[a] = nextAncestor[parent[a]]
            rem[a / BLOCK]++
        } else {
            nextAncestor[a] = parent[a]
        }
    }
    val isBoundary = BooleanArray(n + 1)
    for (a in 0..n step BLOCK) {
        isBoundary[a] = true
    }
    val out = StringBuilder()
    fun getParent(a: Int) = max(1, parent[a] - delta[a / BLOCK])
    fun getNextAncestor(a: Int) = if (getParent(a) / BLOCK == a / BLOCK) nextAncestor[a] else getParent(a)
    for (j in 1..q) {
        if (jin.nextInt() == 1) {
            val from = jin.nextInt()
            val to = jin.nextInt()
            val x = jin.nextInt()
            var a = from
            while (a <= n && (a <= to || !isBoundary[a])) {
                if (a <= to) {
                    if (isBoundary[a] && a + BLOCK - 1 <= to && rem[a / BLOCK] == 0) {
                        delta[a / BLOCK] += x
                        a += BLOCK
                    } else {
                        if (parent[a] / BLOCK == a / BLOCK) {
                            parent[a] -= x
                            parent[a] = max(1, parent[a])
                            if (parent[a] / BLOCK == a / BLOCK) {
                                nextAncestor[a] = getNextAncestor(parent[a])
                            } else {
                                rem[a / BLOCK]--
                            }
                        } else {
                            parent[a] -= x
                        }
                        a++
                    }
                } else {
                    if (parent[a] / BLOCK == a / BLOCK) {
                        nextAncestor[a] = getNextAncestor(parent[a])
                    }
                    a++
                }
            }
        } else {
            var a = jin.nextInt()
            var b = jin.nextInt()
            var c = a
            var d = b
            while (c != d) {
                if (c > d) {
                    a = c
                    c = getNextAncestor(c)
                } else {
                    b = d
                    d = getNextAncestor(d)
                }
            }
            while (a != b) {
                if (a > b) {
                    a = getParent(a)
                } else {
                    b = getParent(b)
                }
            }
            out.appendln(a)
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