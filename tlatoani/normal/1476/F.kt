import java.io.BufferedInputStream
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    val timeSegtree = MinSegmentTree(1, 300001)
    val powerSegtree = MaxSegmentTree(1, 300000)
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        timeSegtree[1] = 0
        for (j in 2..n + 1) {
            timeSegtree[j] = Int.MAX_VALUE
        }
        for (j in 1..n) {
            powerSegtree[j] = 0
        }
        val prev = IntArray(n + 1)
        for (j in 1..n) {
            val power = jin.nextInt()
            val extent = min(n, j + power)
            timeSegtree[extent + 1] = timeSegtree[j + 1, extent + 1]
            if (power != 0 && j - 1 >= 1) {
                val t = timeSegtree[max(1, j - power), j - 1]
                if (t != Int.MAX_VALUE) {
                    prev[j] = t
                    val next = max(j, powerSegtree[t + 1, n] + 1)
                    timeSegtree[next] = min(timeSegtree[next], j)
                }
            }
            powerSegtree[j] = extent
        }
        if (timeSegtree[n + 1] == Int.MAX_VALUE) {
            out.appendln("NO")
        } else {
            out.appendln("YES")
            val answer = CharArray(n + 1) { 'R' }
            var t = timeSegtree[n + 1]
            while (t != 0) {
                answer[t] = 'L'
                t = prev[t]
            }
            out.appendln(String(answer).substring(1))
        }
    }
    print(out)
}

class MinSegmentTree(val treeFrom: Int, treeTo: Int) {
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
            value[node] = min(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromIndex: Int, toIndex: Int): Int {
        if (toIndex < fromIndex) {
            return Int.MAX_VALUE
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Int = Int.MAX_VALUE
        while (from + (from and -from) <= to) {
            res = min(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = min(res, value[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
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
        var res = 0
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