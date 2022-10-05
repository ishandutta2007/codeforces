const val MOD = 1000000007L

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val choose = Array((2 * k) + 1) { LongArray((2 * k) + 1) }
    for (a in 0..2 * k) {
        choose[a][0] = 1L
        for (b in 1..a) {
            choose[a][b] = (choose[a - 1][b] + choose[a - 1][b - 1]) % MOD
        }
    }
    val factorial = LongArray((2 * k) + 1)
    factorial[0] = 1L
    for (a in 1..2 * k) {
        factorial[a] = (a.toLong() * factorial[a - 1]) % MOD
    }
    val dp = Array((2 * k) + 1) { LongArray((2 * k) + 1) }
    dp[0][0] = 1L
    for (a in 1..(2 * k)) {
        for (b in 1..a / 2) {
            for (c in 2..a) {
                dp[a][b] += ((choose[a - 1][c - 1] * factorial[c - 1]) % MOD) * dp[a - c][b - 1]
                dp[a][b] %= MOD
            }
        }
    }
    val answer = LongArray(k + 1)
    for (j in 0..k) {
        if (j >= 2) {
            answer[j] = answer[j - 2]
        }
        var bigChoose = 1L
        for (a in 0..2 * j) {
            if (a > 0) {
                bigChoose *= ((n - a + 1).toLong() * (a.toLong() pow -1)) % MOD
                bigChoose %= MOD
            }
            if (a >= j) {
                answer[j] += bigChoose * dp[a][a - j]
                answer[j] %= MOD
            }
        }
    }
    println(answer.toList().subList(1, k + 1).joinToString(" "))
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