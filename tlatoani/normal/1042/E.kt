import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MOD = 998244353L

fun main() {
    val factorial = LongArray(1000001)
    factorial[0] = 1L
    for (k in 1..1000000) {
        factorial[k] = (k.toLong() * factorial[k - 1]) % MOD
    }
    val invFactorial = LongArray(1000001)
    invFactorial[1000000] = 490058372L
    for (k in 999999 downTo 0) {
        invFactorial[k] = ((k + 1).toLong() * invFactorial[k + 1]) % MOD
    }
    val inv = LongArray(1000001)
    for (k in 1..1000000) {
        inv[k] = (factorial[k - 1] * invFactorial[k]) % MOD
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val cells = mutableListOf<Cell>()
    for (y in 0 until n) {
        val tokenizer = StringTokenizer(jin.readLine())
        for (x in 0 until m) {
            cells.add(Cell(y, x, tokenizer.nextToken().toInt()))
        }
    }
    cells.sortBy { it.rank }
    var k = 0
    val dp = Array(n) { LongArray(m) }
    var ySum = 0L
    var y2Sum = 0L
    var xSum = 0L
    var x2Sum = 0L
    var dpSum = 0L
    for ((y, x, r) in cells) {
        while (k < n * m && cells[k].rank < r) {
            val (v, u) = cells[k]
            ySum += v.toLong()
            y2Sum += (v * v).toLong()
            y2Sum %= MOD
            xSum += u.toLong()
            x2Sum += (u * u).toLong()
            x2Sum %= MOD
            dpSum += dp[v][u]
            dpSum %= MOD
            k++
        }
        if (k > 0) {
            dp[y][x] = (((y * y) + (x * x)).toLong() + (((dpSum - (2L * ySum * y.toLong()) + y2Sum - (2L * xSum * x.toLong()) + x2Sum) % MOD) * inv[k])) % MOD
        }
    }
    val (y, x) = jin.readLine().split(" ").map { it.toInt() - 1 }
    println((dp[y][x] + MOD) % MOD)
}

data class Cell(val y: Int, val x: Int, val rank: Int)