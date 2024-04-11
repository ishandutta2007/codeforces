import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val board = Array(n) { jin.readLine() + "." } + arrayOf(".".repeat(m + 1))
    val s = n * m
    val pow2 = LongArray(s + 1)
    pow2[0] = 1L
    for (k in 1..s) {
        pow2[k] = (2L * pow2[k - 1]) % MOD
    }
    val dpPre = LongArray(s + 1)
    val dp = LongArray(s + 1)
    var prev = 0L
    for (k in 1..s) {
        dpPre[k] = ((2L * dpPre[k - 1]) + ((k - 1) / 2).toLong()) % MOD
        dp[k] = (prev + dpPre[k] + (k / 2).toLong()) % MOD
        prev = (prev + dp[k]) % MOD
    }
    var answer = 0L
    val white = board.sumBy { it.count { it == 'o' } }
    for (y in 0..n) {
        var curr = 0
        for (x in 0..m) {
            if (board[y][x] == 'o') {
                curr++
            } else {
                answer += pow2[white - curr] * dp[curr]
                answer %= MOD
                curr = 0
            }
        }
    }
    for (x in 0..m) {
        var curr = 0
        for (y in 0..n) {
            if (board[y][x] == 'o') {
                curr++
            } else {
                answer += pow2[white - curr] * dp[curr]
                answer %= MOD
                curr = 0
            }
        }
    }
    println(answer)
}