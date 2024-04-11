import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val n = reader.readLine().toInt()
    val tokenizer = StringTokenizer(reader.readLine())
    var sum: Long = 0
    val array = LongArray(n) {
        val a = tokenizer.nextToken().toLong()
        sum += a
        a
    }
    if (sum == 1L) {
        println(-1)
        return
    }
    val primes = mutableListOf<Long>()
    var sumTemp = sum
    for (p in 2L..1000000L) {
        if (sumTemp % p == 0L) {
            while (sumTemp % p == 0L) {
                sumTemp /= p
            }
            primes.add(p)
        }
    }
    if (sumTemp != 1L) {
        primes.add(sumTemp)
    }
    var answer = Long.MAX_VALUE
    //println(factors)
    for (p in primes) {
        val dp = Array(2) { LongArray(2) }
        var residue = array[0] % p
        dp[0][0] = residue
        dp[0][1] = (p - residue) % p
        var b = 0
        var c = 1
        for (j in 1 until n) {
            b = c
            c = 1 - c
            val newResidue = (array[j] + residue) % p
            dp[b][0] = (if (array[j] >= (p - residue) % p) min(dp[c][0], dp[c][1]) else dp[c][0]) + newResidue
            dp[b][1] = min(dp[c][0], dp[c][1]) + ((p - newResidue) % p)
            residue = newResidue
        }
        answer = min(answer, dp[b].min()!!)
    }
    println(answer)
}