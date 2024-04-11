import java.util.*
import kotlin.math.min

fun main() {
    val log = IntArray(29)
    for (color in 0..19) {
        log[(1 shl color) % 29] = color
    }
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val amt = LongArray(20)
    val swapsBelow = Array(20) { LongArray(20) }
    for (i in 1..n) {
        val marble = jin.nextInt() - 1
        for (color in 0..19) {
            swapsBelow[marble][color] += amt[color]
        }
        amt[marble]++
    }

    /*for (color in 0..19) {
        println("swapsBelow[$color] = ${swapsBelow[color].contentToString()}")
    }*/

    val swapsByMask = Array(20) { LongArray(1 shl 20) }
    for (color in 0..19) {
        for (mask in 1 until (1 shl 20)) {
            swapsByMask[color][mask] = swapsByMask[color][mask - (mask and -mask)] + swapsBelow[color][log[(mask and -mask) % 29]]
        }
    }
    val dp = LongArray(1 shl 20) { Long.MAX_VALUE }
    dp[0] = 0
    for (mask in 1 until (1 shl 20)) {
        var b = 1 shl 19
        while (b > 0) {
            if ((mask and b) != 0) {
                dp[mask] = min(dp[mask], dp[mask - b] + swapsByMask[log[b % 29]][mask - b])
            }
            b /= 2
        }
    }
    println(dp.last())
}