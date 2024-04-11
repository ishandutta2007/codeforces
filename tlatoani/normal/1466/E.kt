import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 1000000007L

fun main() {
    val pow2 = LongArray(60) { (1L shl it) % MOD }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toLong()
        val xs = jin.readLine().split(" ").map { it.toLong() }
        val freq = LongArray(60)
        for (x in xs) {
            for (e in 0..59) {
                if ((x shr e) and 1L == 1L) {
                    freq[e]++
                }
            }
        }
        var answer = 0L
        for (x in xs) {
            var left = 0L
            var right = 0L
            for (e in 0..59) {
                if ((x shr e) and 1L == 1L) {
                    left += freq[e] * pow2[e]
                    left %= MOD
                    right += n * pow2[e]
                    right %= MOD
                } else {
                    right += freq[e] * pow2[e]
                    right %= MOD
                }
            }
            answer += left * right
            answer %= MOD
        }
        println(answer)
    }
}