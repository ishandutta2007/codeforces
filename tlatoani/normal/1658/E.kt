import java.io.BufferedInputStream
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val k = jin.nextInt()
    val spots = Array(n * n) { Pair(0, 0) }
    for (y in 0 until n) {
        for (x in 0 until n) {
            spots[jin.nextInt() - 1] = Pair(y, x)
        }
    }
    val answer = Array(n) { CharArray(n) { 'G' } }
    val (yb, xb) = spots.last()
    answer[yb][xb] = 'M'
    var minSum = yb + xb
    var maxSum = yb + xb
    var minDiff = yb - xb
    var maxDiff = yb - xb
    for (j in (n * n) - 2 downTo 0) {
        val (y, x) = spots[j]
        val sum = y + x
        val diff = y - x
        val maxDist = max(
                max(sum - minSum, maxSum - sum),
                max(diff - minDiff, maxDiff - diff)
        )
        if (maxDist <= k) {
            answer[y][x] = 'M'
            minSum = min(minSum, sum)
            maxSum = max(maxSum, sum)
            minDiff = min(minDiff, diff)
            maxDiff = max(maxDiff, diff)
        }
    }
    println(answer.joinToString("\n") { String(it) })
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