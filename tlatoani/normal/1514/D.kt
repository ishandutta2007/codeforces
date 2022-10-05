import java.io.BufferedInputStream

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val q = jin.nextInt()
    val xs = intArrayOf(0) + IntArray(n) { jin.nextInt() }
    val freq = IntArray(n + 1)
    val amtAtFreq = IntArray(n + 1)
    var from = 1
    var to = 1
    freq[xs[1]] = 1
    amtAtFreq[1] = 1
    var maxFreq = 1
    val queries = Array(q) {
        val l = jin.nextInt()
        val r = jin.nextInt()
        Query(l, r, it)
    }
    queries.sortWith(compareBy({ it.from / 550 }, { it.to }))
    val answer = IntArray(q)
    for ((l, r, j) in queries) {
        while (from > l) {
            from--
            val x = xs[from]
            amtAtFreq[freq[x]]--
            freq[x]++
            amtAtFreq[freq[x]]++
            if (freq[x] > maxFreq) {
                maxFreq++
            }
        }
        while (to < r) {
            to++
            val x = xs[to]
            amtAtFreq[freq[x]]--
            freq[x]++
            amtAtFreq[freq[x]]++
            if (freq[x] > maxFreq) {
                maxFreq++
            }
        }
        while (from < l) {
            val x = xs[from]
            amtAtFreq[freq[x]]--
            freq[x]--
            amtAtFreq[freq[x]]++
            if (amtAtFreq[maxFreq] == 0) {
                maxFreq--
            }
            from++
        }
        while (to > r) {
            val x = xs[to]
            amtAtFreq[freq[x]]--
            freq[x]--
            amtAtFreq[freq[x]]++
            if (amtAtFreq[maxFreq] == 0) {
                maxFreq--
            }
            to--
        }
        answer[j] = if (maxFreq <= (r - l + 2) / 2) {
            1
        } else {
            2 * (maxFreq - ((r - l + 2) / 2)) + ((r - l + 1) % 2)
        }
    }
    println(answer.joinToString("\n"))
}

data class Query(val from: Int, val to: Int, val index: Int)

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