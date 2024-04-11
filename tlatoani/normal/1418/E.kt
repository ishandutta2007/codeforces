import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 998244353L

fun main() {
    val factorial = LongArray(200002)
    factorial[0] = 1L
    for (j in 1..200001) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val factInv = LongArray(200002)
    factInv[200001] = factorial[200001] pow -1
    for (j in 200000 downTo 0) {
        factInv[j] = ((j + 1).toLong() * factInv[j + 1]) % MOD
    }
    val inv = LongArray(200002) { if (it == 0) 0L else (factorial[it - 1] * factInv[it]) % MOD }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val monsters = jin.readLine().split(" ").map { it.toLong() }.sorted()
    val shields = Array(m) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        Shield(a, b.toLong(), it)
    }
    shields.sortBy { it.defence }
    var x = 0
    var y = n
    var sx = 0L
    var sy = monsters.sum()
    var k = 0
    val answer = LongArray(m)
    for (shield in shields) {
        while (k < n && monsters[k] < shield.defence) {
            x++
            y--
            sx += monsters[k]
            sy -= monsters[k]
            k++
        }
        if (shield.durability <= y) {
            answer[shield.index] = ((sx % MOD) * (((y + 1 - shield.durability).toLong() * inv[y + 1]) % MOD)) + ((sy % MOD) * (((y - shield.durability).toLong() * inv[y]) % MOD))
            answer[shield.index] %= MOD
        }
    }
    println(answer.joinToString("\n"))
}

data class Shield(val durability: Int, val defence: Long, val index: Int)

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