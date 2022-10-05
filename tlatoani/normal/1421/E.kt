import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val heroes = listOf(0L) + readLine()!!.split(" ").map { it.toLong() }
    if (n == 1) {
        println(heroes[1])
        return
    }
    val dp = Array(n + 1) { Array(2) { LongArray(3) { -400000L * 1000000000L } } }
    dp[0][0][0] = 0L
    for (j in 1..n) {
        for (b in 0..2) {
            for (a in 0..1) {
                dp[j][a][b] = max(dp[j - 1][a][b] - heroes[j], dp[j - 1][a][(b + 2) % 3] + heroes[j])
            }

            if (j >= 2) {
                dp[j][1][b] = maxOf(dp[j][1][b], dp[j - 2][0][b] - heroes[j - 1] - heroes[j], dp[j - 2][0][(b + 1) % 3] + heroes[j - 1] + heroes[j])
            }
        }
    }
    println(dp[n][1][(if (n % 2 == 0) ((n / 2) - 1) else ((n + 1) / 2)) % 3])
}