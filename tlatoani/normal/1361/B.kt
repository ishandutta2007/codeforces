import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 1000000007L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val p = line[1].toLong()
        val powers = jin.readLine().split(" ").map { it.toInt() }.sortedDescending()
        var answer = 0L
        var passed = false
        var prevPower = powers[0]
        var limit = 0
        var limitTester = 1L
        if (p == 1L) {
            limit = Int.MAX_VALUE
        } else {
            while (limitTester <= n) {
                limit++
                limitTester *= p
            }
        }
        for (k in powers) {
            var rem = prevPower - k
            if (!passed && answer != 0L && rem >= limit) {
                passed = true
            }
            answer *= p pow rem
            if (!passed && answer > n) {
                passed = true
            }
            if (passed) {
                answer %= MOD
            }
            //println("answer = $answer")
            if (answer > 0L || passed) {
                answer--
                answer %= MOD
            } else {
                answer = 1L
            }
            prevPower = k
            //println("k = $k, answer = $answer")
        }
        answer *= p pow powers.last()
        answer %= MOD
        answer += MOD
        answer %= MOD
        out.appendln(answer)
    }
    print(out)
}

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

/*
1
5 2
2 3 4 4 3

 */