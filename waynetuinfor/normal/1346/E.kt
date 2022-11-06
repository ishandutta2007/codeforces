import java.util.*
import kotlin.math.*

fun Solve() {
    var (n, m, k) = readLine()!!.split(" ").map{ it.toInt() }
    k -= 1
    val x = IntArray(m)
    val y = IntArray(m)
    for (i in 0 until m) {
        val (xi, yi) = readLine()!!.split(" ").map{ it.toInt() }
        x[i] = xi - 1
        y[i] = yi - 1
    }
    val dp = IntArray(n, { i -> m + 1 })
    dp[k] = 0
    for (i in 0 until m) {
        var d0 = dp[x[i]]
        var d1 = dp[y[i]]
        dp[x[i]] = min(dp[x[i]] + 1, d1)
        dp[y[i]] = min(dp[y[i]] + 1, d0)
    }
    for (d in dp) {
        if (d == m + 1) print("-1 ")
        else print(d.toString() + " ")
    }
    println()
}

fun main() {
    var t = 1
    while (t-- > 0) {
        Solve()
    }
}