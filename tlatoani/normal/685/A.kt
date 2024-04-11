import java.io.BufferedInputStream

fun main() {
    val pows = LongArray(40)
    pows[0] = 1L
    for (e in 1..39) {
        pows[e] = 7L * pows[e - 1]
    }
    val jin = FastScanner()
    val n = jin.nextInt().toLong()
    val m = jin.nextInt().toLong()
    var e = 1
    var pow = 7L
    while (pow < n) {
        e++
        pow *= 7L
    }
    var f = 1
    pow = 7L
    while (pow < m) {
        f++
        pow *= 7L
    }
    val used = mutableSetOf<Int>()
    var answer = 0
    var hour = 0L
    var minute = 0L
    fun recur(d: Int) {
        if (d == e + f) {
            if (hour < n && minute < m) {
                answer++
            }
        } else {
            for (digit in 0..6) {
                if (digit !in used) {
                    used.add(digit)
                    if (d < e) {
                        hour += digit.toLong() * pows[d]
                    } else {
                        minute += digit.toLong() * pows[d - e]
                    }
                    recur(d + 1)
                    if (d < e) {
                        hour -= digit.toLong() * pows[d]
                    } else {
                        minute -= digit.toLong() * pows[d - e]
                    }
                    used.remove(digit)
                }
            }
        }
    }
    recur(0)
    println(answer)
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