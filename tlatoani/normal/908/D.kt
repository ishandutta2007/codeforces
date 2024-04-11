import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val k = jin.nextInt()
    val pa = jin.nextLong()
    val pb = jin.nextLong()
    val p = (pa * ((pa + pb) pow -1)) % MOD
    val np = 1L - p
    val npInv = np pow -1
    //println("p = $p, np = $np, npInv = $npInv")
    val dp = Array(k) { LongArray(k + 1) }
    var answer = k.toLong()
    dp[0][1] = 1L
    for (j1 in 0 until k) {
        for (j2 in 1..k) {
            //println("dp[$j1][$j2] = ${dp[j1][j2]}")
            if (j2 == k) {
                answer += dp[j1][j2] * (j1.toLong() + npInv - 1L)
                answer %= MOD
            } else {
                dp[j1][j2 + 1] += dp[j1][j2] * p
                dp[j1][j2 + 1] %= MOD
                if (j1 + j2 >= k) {
                    answer += ((dp[j1][j2] * np) % MOD) * (j1 + j2 - k).toLong()
                    answer %= MOD
                } else {
                    dp[j1 + j2][j2] += dp[j1][j2] * np
                    dp[j1 + j2][j2] %= MOD
                }
            }
        }
    }
    println(((answer % MOD) + MOD) % MOD)
}

val MOD: Long = 1000000007
val MOD_TOTIENT = (MOD - 1).toInt()

infix fun Long.pow(power: Int): Long {
    var e = power
    e %= MOD_TOTIENT
    if (e < 0) {
        e += MOD_TOTIENT
    }
    if (e == 0 && this == 0L) {
        return this
    }
    var b = this
    var res = 1L
    while (e > 0) {
        if (e and 1 != 0) {
            res *= b
            res %= MOD
        }
        b *= b
        b %= MOD
        e = e shr 1
    }
    return res
}