const val MOD = 1000000007L

fun main() {
    val n = readLine()!!.toInt()
    val strengths = readLine()!!.split(" ").map { it.toLong() }
    val probabilities = Array(n) { a -> LongArray(n) { b -> (strengths[a] * ((strengths[a] + strengths[b]) pow -1)) % MOD } }
    val probabilitiesCombined = Array(n) { a -> LongArray(1 shl n) { mask ->
        var res = 1L
        for (b in 0 until n) {
            if (mask and (1 shl b) != 0) {
                res *= probabilities[a][b]
                res %= MOD
            }
        }
        res
    } }
    val dp = LongArray(1 shl n) { 1L }
    dp[0] = 0L
    fun recur(j: Int, mask: Int, submask: Int) {
        if (j == n) {
            if (submask != mask) {
                var toSubtract = dp[submask]
                for (a in 0 until n) {
                    if (submask and (1 shl a) != 0) {
                        toSubtract *= probabilitiesCombined[a][mask - submask]
                        toSubtract %= MOD
                    }
                }
                dp[mask] -= toSubtract
                dp[mask] %= MOD
            }
        } else {
            recur(j + 1, mask, submask)
            recur(j + 1, mask or (1 shl j), submask)
            recur(j + 1, mask or (1 shl j), submask or (1 shl j))
        }
    }
    recur(0, 0, 0)
    var answer = 0L
    for ((mask, x) in dp.withIndex()) {
        var addend = x
        for (a in 0 until n) {
            if (mask and (1 shl a) != 0) {
                addend *= probabilitiesCombined[a][dp.lastIndex - mask]
                addend %= MOD
            }
        }
        answer += Integer.bitCount(mask).toLong() * addend
        answer %= MOD
    }
    answer += MOD
    answer %= MOD
    println(answer)
}

const val MOD_TOTIENT = MOD.toInt() - 1

infix fun Long.pow(power: Int): Long {
    var e = power
    e %= MOD_TOTIENT
    if (e < 0) {
        e += MOD_TOTIENT
    }
    if (e == 0 && this == 0L) {
        return this
    }
    var b = this % MOD
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