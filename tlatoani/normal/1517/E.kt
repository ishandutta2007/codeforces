import java.io.BufferedInputStream

const val MOD = 998244353L

fun main() {
    val jin = FastScanner()
    val out = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val ay = Array(n) { jin.nextInt().toLong() }.reversed()
        val s = ay.sum()
        val neces = s / 2L
        var answer = 0L
        for (x in 1..2) {
            for (y in 1..2) {
                if (x + y <= n) {
                    answer += solveGeneral(ay.subList(x, n - y), neces - (if (x == 1) ay[0] else ay[1]) - (if (y == 1) 0L else ay[n - 1]))
                }
            }
        }
        answer %= MOD
        var curr = 0L
        for (j in n - 1 downTo 0) {
            curr += ay[j]
            if (curr > neces) {
                answer++
            }
        }
        answer %= MOD
        out.appendln(answer)
    }
    print(out)
}

fun solveGeneral(ay: List<Long>, neces: Long): Long {
    if (ay.isEmpty()) {
        return if (neces < 0L) 1L else 0L
    } else if (ay.size == 1) {
        return when {
            neces < 0L -> 2L
            neces < ay[0] -> 1L
            else -> 0L
        }
    }
    var res = 0L
    var n = ay.size - (ay.size % 2)
    var k = n
    var curr = 0L
    for (j in 1 until k step 2) {
        curr += ay[j]
    }
    while (k > 0 && curr - ay[k - 1] > neces) {
        curr -= ay[k - 1]
        k -= 2
    }
    if (curr > neces) {
        res += ((n - k) / 2) + 1
    }
    for (j in 0 until n step 2) {
        curr += ay[j]
        if (k == j) {
            k += 2
            curr += ay[k - 1]
        }
        while (k > j + 2 && curr - ay[k - 1] > neces) {
            curr -= ay[k - 1]
            k -= 2
        }
        if (curr > neces) {
            res += ((n - k) / 2) + 1
        }
    }
    curr = ay[0]
    n = ay.size - (1 - (ay.size % 2))
    k = n
    for (j in 2 until k step 2) {
        curr += ay[j]
    }
    while (k > 1 && curr - ay[k - 1] > neces) {
        curr -= ay[k - 1]
        k -= 2
    }
    if (curr > neces) {
        res += ((n - k) / 2) + 1
    }
    for (j in 1 until n step 2) {
        curr += ay[j]
        if (k == j) {
            k += 2
            curr += ay[k - 1]
        }
        while (k > j + 2 && curr - ay[k - 1] > neces) {
            curr -= ay[k - 1]
            k -= 2
        }
        if (curr > neces) {
            res += ((n - k) / 2) + 1
        }
    }
    res %= MOD
    return res
}

/*


1
5
2 1 2 1 1


 */

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