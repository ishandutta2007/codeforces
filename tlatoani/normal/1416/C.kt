import java.io.BufferedInputStream

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val elems = Array(n) { jin.nextInt() }
    var totalInversions = 0L
    var x = 0
    for (e in 29 downTo 0) {
        elems.sortBy { it shr (e + 1) }
        var inversions0 = 0L
        var inversions1 = 0L
        var prev0 = 0L
        var prev1 = 0L
        for (j in 0 until n) {
            if (j > 0 && elems[j] shr (e + 1) != elems[j - 1] shr (e + 1)) {
                prev0 = 0L
                prev1 = 0L
            }
            if (elems[j] and (1 shl e) == 0) {
                inversions0 += prev1
                prev0++
            } else {
                inversions1 += prev0
                prev1++
            }
        }
        if (inversions0 <= inversions1) {
            totalInversions += inversions0
        } else {
            totalInversions += inversions1
            x += 1 shl e
        }
    }
    println("$totalInversions $x")
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