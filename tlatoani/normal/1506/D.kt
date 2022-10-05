import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val freq = mutableMapOf<Int, Int>()
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            val k = tokenizer.nextToken().toInt()
            freq[k] = (freq[k] ?: 0) + 1
        }
        out.appendln(n - (2 * min(n / 2, n - freq.values.max()!!)))
    }
    print(out)
}