import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val k = line[1].toLong()
        val freq = mutableMapOf<Long, Long>()
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            val a = tokenizer.nextToken().toLong()
            val r = k - (a % k)
            if (r != k) {
                freq[r] = (freq[r] ?: 0L) + 1L
            }
        }
        var answer = -1L
        for ((r, f) in freq) {
            answer = max(answer, r + (k * (f - 1L)))
        }
        println(answer + 1L)
    }
}