import java.io.BufferedInputStream
import kotlin.math.max

const val MOD = 1000000007L

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val cs = IntArray(n) { jin.nextInt() }
    val bs = IntArray(n - 1) { jin.nextInt() }
    var curr = 0
    var minSum = 0
    var maxSum = 0
    for (j in 0 until n) {
        minSum += curr
        maxSum += curr + cs[j]
        if (j < n - 1) {
            curr -= bs[j]
        }
    }
    val m = cs.sum()
    val answers = mutableMapOf<Int, Long>()
    for (average in (minSum - n) / n..maxSum / n) {
        curr = -average
        var sum = 0
        var prevDP = LongArray(m + 1)
        prevDP[0] = 1L
        var nextDP = LongArray(m + 1)
        for (j in 0 until n) {
            var sliding = 0L
            for (x in 0..m) {
                if (sum + x >= 0) {
                    sliding += prevDP[x]
                    if (sliding >= MOD) {
                        sliding -= MOD
                    }
                }
                if (x > cs[j] && sum + x - cs[j] > 0) {
                    sliding -= prevDP[x - cs[j] - 1]
                    if (sliding < 0L) {
                        sliding += MOD
                    }
                }
                nextDP[x] = sliding
            }
            val temp = prevDP
            prevDP = nextDP
            nextDP = temp
            sum += curr
            if (j < n - 1) {
                curr -= bs[j]
            }
        }
        var answer = 0L
        for (x in 0..m) {
            if (sum + x >= 0) {
                answer += prevDP[x]
            }
        }
        answer %= MOD
        answers[average] = answer
    }
    val out = StringBuilder()
    repeat(jin.nextInt()) {
        val average = jin.nextInt()
        out.appendln(answers[max((minSum - n) / n, average)] ?: 0L)
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