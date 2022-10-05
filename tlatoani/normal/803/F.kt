import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MOD = 1000000007L

fun main() {
    val factors = Array(100001) { mutableListOf<Int>() }
    for (f in 100000 downTo 1) {
        for (k in f..100000 step f) {
            factors[k].add(f)
        }
    }
    val mobius = LongArray(100001)
    mobius[1] = 1L
    for (k in 2..100000) {
        for (f in factors[k]) {
            mobius[k] -= mobius[f]
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val dp = LongArray(100001) { 1L }
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        for (f in factors[k]) {
            dp[f] *= 2L
            if (dp[f] >= MOD) {
                dp[f] -= MOD
            }
        }
    }
    var answer = 0L
    for (k in 1..100000) {
        answer += mobius[k] * (dp[k] - 1L)
        answer %= MOD
    }
    if (answer < 0L) {
        answer += MOD
    }
    println(answer)
}