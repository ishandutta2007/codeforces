const val MOD = 998244353L

fun main() {
    val x = (" " + readLine()!!).map { it - 'a' }
    val y = (" " + readLine()!!).map { it - 'a' }
    val dp = Array(27) { letter -> Array(x.size) { LongArray(y.size) { if (letter == 26) 1L else 0L } } }
    var answer = 0L
    for (a in x.indices) {
        for (b in y.indices) {
            if (a > 0) {
                dp[x[a]][a][b] += dp[26][a - 1][b] - dp[x[a]][a - 1][b]
                dp[x[a]][a][b] %= MOD
            }
            if (b > 0) {
                dp[y[b]][a][b] += dp[26][a][b - 1] - dp[y[b]][a][b - 1]
                dp[y[b]][a][b] %= MOD
            }
            if (a > 0) {
                dp[26][a][b] += dp[x[a]][a][b]
            }
            if (b > 0 && y[b] != x[a]) {
                dp[26][a][b] += dp[y[b]][a][b]
            }
            dp[26][a][b] %= MOD
            answer += dp[26][a][b]
            answer %= MOD
        }
    }
    //println(answer)
    answer -= (x.size * y.size).toLong()
    answer %= MOD
    for (a in 1 until x.size) {
        var b = a + 1
        while (b < x.size && x[b] != x[b - 1]) {
            b++
        }
        answer -= ((b - a) * y.size).toLong()
        answer %= MOD
    }
    for (a in 1 until y.size) {
        var b = a + 1
        while (b < y.size && y[b] != y[b - 1]) {
            b++
        }
        answer -= (x.size * (b - a)).toLong()
        answer %= MOD
    }
    answer += MOD
    answer %= MOD
    println(answer)
}