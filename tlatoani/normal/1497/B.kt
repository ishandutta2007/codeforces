import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val freqs = IntArray(m)
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            freqs[tokenizer.nextToken().toInt() % m]++
        }
        var answer = 0
        if (freqs[0] != 0) {
            answer++
        }
        if (m % 2 == 0 && freqs[m / 2] != 0) {
            answer++
        }
        for (k in 1 until (m + 1) / 2) {
            val a = min(freqs[k], freqs[m - k])
            val b = max(freqs[k], freqs[m - k])
            if (b != 0) {
                answer += 1 + max(0, b - (a + 1))
            }
        }
        println(answer)
    }
}