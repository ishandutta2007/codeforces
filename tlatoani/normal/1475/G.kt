import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val divisors = Array(200001) { mutableListOf<Int>() }
    for (d in 1..200000) {
        for (f in d + d..200000 step d) {
            divisors[f].add(d)
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val freq = IntArray(200001)
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            freq[tokenizer.nextToken().toInt()]++
        }
        val dp = IntArray(200001)
        for (k in 1..200000) {
            dp[k] = freq[k]
            for (d in divisors[k]) {
                dp[k] = max(dp[k], freq[k] + dp[d])
            }
        }
        println(n - dp.max()!!)
    }
}