import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val freqMap = mutableMapOf<Int, Int>()
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            val k = tokenizer.nextToken().toInt()
            freqMap[k] = (freqMap[k] ?: 0) + 1
        }
        val freqs = freqMap.values.sorted()
        var answer = Int.MAX_VALUE
        for ((j, f) in freqs.withIndex()) {
            answer = min(answer, n - ((freqs.size - j) * f))
        }
        println(answer)
    }
}