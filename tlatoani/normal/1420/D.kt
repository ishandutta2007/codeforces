import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 998244353L

fun main() {
    val factorial = LongArray(300001)
    factorial[0] = 1L
    for (j in 1..300000) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val factInv = LongArray(300001)
    factInv[300000] = factorial[300000] pow -1
    for (j in 299999 downTo 0) {
        factInv[j] = ((j + 1).toLong() * factInv[j + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (a < 0 || b < 0 || a < b) 0L else (factorial[a] * ((factInv[b] * factInv[a - b]) % MOD)) % MOD
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = jin.readLine().split(" ").map { it.toInt() }
    val lampsOn = Array(n) {
        val (l, r) = jin.readLine().split(" ").map { it.toInt() }
        Lamp(l, r)
    }
    val lampsOff = lampsOn.clone()
    lampsOn.sortBy { it.on }
    lampsOff.sortBy { it.off }
    var j = 0
    var amtLamps = 0
    var answer = 0L
    for (lamp in lampsOn) {
        while (j < n && lampsOff[j].off < lamp.on) {
            amtLamps--
            j++
        }
        amtLamps++
        answer += choose(amtLamps - 1, k - 1)
        answer %= MOD
    }
    println(answer)
}

data class Lamp(val on: Int, val off: Int)

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