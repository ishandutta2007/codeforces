import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (r, n) = jin.readLine().split(" ").map { it.toInt() }
    val vips = Array(n) {
        val (t, x, y) = jin.readLine().split(" ").map { it.toInt() }
        VIP(x, y, t)
    }
    val dp = IntArray(n) { -1 }
    var most = 0
    for (j in 0 until n) {
        if (vips[j].x + vips[j].y - 2 <= vips[j].t) {
            if (j >= 1000) {
                most = max(most, dp[j - 1000])
            }
            dp[j] = most
            for (k in max(0, j - 999) until j) {
                if (abs(vips[j].x - vips[k].x) + abs(vips[j].y - vips[k].y) <= vips[j].t - vips[k].t) {
                    dp[j] = max(dp[j], dp[k])
                }
            }
            dp[j]++
        }
    }
    println(max(0, dp.max()!!))
}

data class VIP(val x: Int, val y: Int, val t: Int)