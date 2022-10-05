import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    jin.readLine()
    val ay = jin.readLine().split(" ").map { it.toInt() }
    val by = jin.readLine().split(" ").map { it.toInt() }
    val dp = BooleanArray(512)
    for (b in by) {
        dp[b] = true
    }
    for (mask in 0..510) {
        for (e in 0..8) {
            dp[mask or (1 shl e)] = dp[mask or (1 shl e)] or dp[mask]
        }
    }
    var res = 0
    for (e in 8 downTo 0) {
        res += 1 shl e
        if (!ay.all { dp[511 - (it and res)] }) {
            res -= 1 shl e
        }
    }
    println(511 - res)
}