import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val freq = mutableMapOf<Int, Long>()
        var answer = 0L
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            val k = tokenizer.nextToken().toInt() - j
            answer += freq[k] ?: 0
            freq[k] = (freq[k] ?: 0) + 1
        }
        out.appendln(answer)
    }
    print(out)
}