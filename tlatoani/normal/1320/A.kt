import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val freq = mutableMapOf<Int, Long>()
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..n) {
        val b = tokenizer.nextToken().toLong()
        freq[j - b.toInt()] = (freq[j - b.toInt()] ?: 0L) + b
    }
    var answer = 0L
    for (v in freq.values) {
        answer = max(answer, v)
    }
    println(answer)
}