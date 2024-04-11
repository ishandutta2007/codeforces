import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs

val PRIMES = mutableListOf(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53)
val IMPORTANT = (1..30) + listOf(31, 32, 37, 41, 43, 47, 49, 53)

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val masks = IntArray(54)
    for (k in 1..53) {
        for (e in 0..15) {
            if (k % PRIMES[e] == 0) {
                masks[k] += 1 shl e
            }
        }
    }
    val dp = Array(n + 1) { IntArray(1 shl 16) { 115115 } }
    dp[0][0] = 0
    val used = Array(n + 1) { IntArray(1 shl 16) }
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..n) {
        val a = tokenizer.nextToken().toInt()
        for (k in IMPORTANT) {
            for (mask in 0 until (1 shl 16)) {
                if (mask and masks[k] == 0 && dp[j - 1][mask] + abs(k - a) < dp[j][mask or masks[k]]) {
                    dp[j][mask or masks[k]] = dp[j - 1][mask] + abs(k - a)
                    used[j][mask or masks[k]] = k
                }
            }
        }
    }
    val optimal = dp[n].min()!!
    for (mask in 0 until (1 shl 16)) {
        if (dp[n][mask] == optimal) {
            val answer = mutableListOf<Int>()
            var mask = mask
            for (j in n downTo 1) {
                answer.add(used[j][mask])
                mask -= masks[used[j][mask]]
            }
            println(answer.reversed().joinToString(" "))
            return
        }
    }
}