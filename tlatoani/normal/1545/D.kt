import java.io.BufferedInputStream

fun main() {
    val jin = FastScanner()
    val m = jin.nextInt()
    val k = jin.nextInt()
    val positions = Array(k) { LongArray(m) { jin.nextInt().toLong() } }
    val sums = positions.map { it.sum() }
    val sums2 = positions.map { it.map { it * it }.sum() }
    val ds = mutableListOf<Long>()
    val freq = mutableMapOf<Long, Int>()
    for (j in 1 until k) {
        ds.add(sums[j] - sums[j - 1])
        freq[ds.last()] = (freq[ds.last()] ?: 0) + 1
    }
    val d = ds.maxBy { freq[it]!! }!!
    val y = if (ds.count { it != d } == 1 && ds.first() != d) 0 else { ds.indexOfFirst { it != d } + 1 }
    val d20: Long
    val d21: Long
    if (y >= 3) {
        d21 = (sums2[2] - sums2[1]) - (sums2[1] - sums2[0])
        d20 = (sums2[1] - sums2[0]) - d21
    } else {
        d21 = (sums2[6] - sums2[5]) - (sums2[5] - sums2[4])
        d20 = (sums2[5] - sums2[4]) - (5 * d21)
    }
    val expected = if (y == 0) { sums[1] - d } else { sums[y - 1] + d }
    val expected2 = if (y == 0) { sums2[1] - d20 - d21 } else { sums2[y - 1] + d20 + (y.toLong() * d21) }
    for (j in 0 until m) {
        val new = positions[y][j] + expected - sums[y]
        if (sums2[y] - (positions[y][j] * positions[y][j]) + (new * new) == expected2) {
            println("$y $new")
            return
        }
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