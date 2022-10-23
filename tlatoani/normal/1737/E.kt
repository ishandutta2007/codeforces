const val MOD = 1000000007L
const val HALF = (MOD + 1L) / 2L

fun main() {
    val out = StringBuilder()
    val pow = LongArray(1000001)
    pow[0] = 1L
    for (x in 1..1000000) {
        pow[x] = (HALF * pow[x - 1]) % MOD
    }
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val dp = LongArray(n + 2) { 1L }
        dp[n + 1] = 0L
        for (x in n / 2 downTo 1) {
            dp[x] = dp[x + 1]
            if (2 * x == n) {
                dp[x] -= pow[x - 1] * dp[2 * x]
            } else {
                dp[x] -= pow[x] * dp[2 * x]
            }
            if ((2 * x) + 1 == n) {
                dp[x] -= pow[x] * dp[(2 * x) + 1]
            } else {
                dp[x] -= pow[x + 1] * dp[(2 * x) + 1]
            }
            dp[x] %= MOD
        }
        for (x in 1..n) {
            var res = pow[x - (x / 2) - (if (x == n) 1 else 0)] * dp[x]
            res %= MOD
            res += MOD
            res %= MOD
            out.appendln(res)
        }
    }
    print(out)
}