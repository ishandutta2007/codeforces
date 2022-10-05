const val MOD = 1000000007L

fun main() {
    val factorial = LongArray(200001)
    factorial[0] = 1L
    for (k in 1..200000) {
        factorial[k] = (k.toLong() * factorial[k - 1]) % MOD
    }
    val invFactorial = LongArray(200001)
    invFactorial[200000] = 750007460L
    for (k in 199999 downTo 0) {
        invFactorial[k] = ((k + 1).toLong() * invFactorial[k + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (b in 0..a) (factorial[a] * ((invFactorial[b] * invFactorial[a - b]) % MOD)) % MOD else 0L
    val (h, w, n) = readLine()!!.split(" ").map { it.toInt() }
    val blackSpots = (Array(n) {
        val (y, x) = readLine()!!.split(" ").map { it.toInt() }
        Pair(y, x)
    } + arrayOf(Pair(h, w))).sortedWith(compareBy({ it.first }, { it.second }))
    val dp = LongArray(n + 1)
    for (j in 0..n) {
        val (y, x) = blackSpots[j]
        dp[j] = choose(y + x - 2, y - 1)
        for (k in 0 until j) {
            val (v, u) = blackSpots[k]
            if (v <= y && u <= x) {
                dp[j] -= choose(y + x - v - u, y - v) * dp[k]
                dp[j] %= MOD
            }
        }
    }
    println((dp[n] + MOD) % MOD)
}