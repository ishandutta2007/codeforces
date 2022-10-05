import java.util.*

const val MOD = 998244353

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val k = jin.nextInt()
    val array = Array(n) { jin.nextInt() }
    array.sort()
    var answer = 0L
    val dp = Array(n) { IntArray(k + 1) }
    for (b in 1..100000 / (k - 1)) {
        dp.forEach { it.fill(0) }
        dp[0][1] = 1
        var p = 0
        for (q in 1 until n) {
            for (j in 0..k) {
                dp[q][j] = dp[q - 1][j]
            }
            while (array[q] - array[p] >= b) {
                for (j in 1..k) {
                    dp[q][j] += dp[p][j - 1]
                    if (dp[q][j] >= MOD) {
                        dp[q][j] -= MOD
                    }
                }
                p++
            }
            answer += dp[q][k]
            if (answer >= MOD) {
                answer -= MOD
            }
        }
    }
    println(answer)
}