import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val m = jin.nextInt()
        val b = 1 shl n
        /*val equivalent = mutableMapOf<Int, Int>()
        for (mask in 0 until b) {
            if (!equivalent.containsKey(mask)) {
                var currMask = mask
                for (i in 0 until n) {
                    equivalent[currMask] = mask
                    currMask *= 2
                    if (currMask >= b) {
                        currMask -= b
                        currMask++
                    }
                }
            }
        }*/
        val matrix = Array(n) { IntArray(m) { jin.nextInt() } }
        println(dp(n, b, matrix, 0, m - 1)[b - 1])
    }
}

fun dp(n: Int, b: Int, matrix: Array<IntArray>, from: Int, to: Int): IntArray {
    val res = IntArray(b)
    if (from == to) {
        for (mask in 1 until b) {
            for (i in 0 until n) {
                var curr = 0
                for (j in 0 until n) {
                    if ((mask and (1 shl ((i + j) % n))) != 0) {
                        curr += matrix[j][from]
                    }
                }
                res[mask] = max(res[mask], curr)
            }
        }
    } else {
        val left = dp(n, b, matrix, from, from)
        val right = dp(n, b, matrix, from + 1, to)
        for (mask1 in 0 until b) {
            for (mask2 in 0 until b) {
                if ((mask1 and mask2) == 0) {
                    res[mask1 or mask2] = max(res[mask1 or mask2], left[mask1] + right[mask2])
                }
            }
        }
    }
    return res
}