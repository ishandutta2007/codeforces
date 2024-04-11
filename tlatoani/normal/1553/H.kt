import java.io.BufferedInputStream
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val k = jin.nextInt()
    val trie = BooleanArray(1 shl (k + 1))
    repeat(n) {
        var x = (1 shl k) + jin.nextInt()
        while (x != 0) {
            trie[x] = true
            x /= 2
        }
    }
    val answers = IntArray(1 shl k) { 1 shl k }
    for (split in 0 until k) {
        for (ending in 0 until (1 shl (split + 1))) {
            var here = 1 shl k
            for (beginning in 0 until (1 shl (k - split - 1))) {
                val x = (1 shl k) + (beginning shl (split + 1)) + ending
                if (trie[x shr split] && trie[(x shr split) xor 1]) {
                    var left = 0
                    var right = 1 shl split
                    for (j in split - 1 downTo 0) {
                        if (trie[((x xor left) shr j) xor 1]) {
                            left += 1 shl j
                        }
                        if (!trie[(x xor right) shr j]) {
                            right += 1 shl j
                        }
                    }
                    here = min(here, right - left)
                }
            }
            for (beginning in 0 until (1 shl (k - split - 1))) {
                val x = (beginning shl (split + 1)) + ending
                answers[x] = min(answers[x], here)
            }
        }
    }
    println(answers.joinToString(" "))
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