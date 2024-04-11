import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val dp = IntArray(1 shl 20)
    var masks = mutableListOf(0)
    for (chara in jin.readLine()) {
        val b = 1 shl (chara - 'a')
        val new = mutableListOf(0)
        for (mask in masks) {
            if (mask or b == mask) {
                break
            }
            new.add(mask or b)
        }
        masks = new
        masks.forEach { dp[it] = Integer.bitCount(it) }
    }
    for (mask in 0 until (1 shl 20)) {
        for (e in 0..19) {
            dp[mask or (1 shl e)] = max(dp[mask or (1 shl e)], dp[mask])
        }
    }
    var answer = 0
    for (mask in 0 until (1 shl 20)) {
        answer = max(answer, dp[mask] + dp[(1 shl 20) - 1 - mask])
    }
    println(answer)
}