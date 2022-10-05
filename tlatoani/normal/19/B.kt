import java.io.BufferedInputStream
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val items = Array(n) {
        val t = jin.nextInt()
        val c = jin.nextInt()
        Item(c.toLong(), t + 1)
    }
    val dp = LongArray(4001) { Long.MAX_VALUE }
    dp[0] = 0L
    for (item in items) {
        for (j in 4000 downTo item.time) {
            if (dp[j - item.time] != Long.MAX_VALUE) {
                dp[j] = min(dp[j], dp[j - item.time] + item.cost)
            }
        }
    }
    println(dp.toList().subList(n, 4000).min())
}

data class Item(val cost: Long, val time: Int)

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