import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        var tokenizer = StringTokenizer(jin.readLine())
        val n = tokenizer.nextToken().toInt()
        val k = tokenizer.nextToken().toInt()
        tokenizer = StringTokenizer(jin.readLine())
        val array = IntArray(n) { tokenizer.nextToken().toInt() }
        val deltas = IntArray((2 * k) + 2)
        for (j in 0 until n / 2) {
            deltas[2] += 2
            deltas[min(array[j], array[n - j - 1]) + 1]--
            deltas[array[j] + array[n - j - 1]]--
            deltas[array[j] + array[n - j - 1] + 1]++
            deltas[max(array[j], array[n - j - 1]) + k + 1]++
        }
        var answer = Int.MAX_VALUE
        for (j in 2..2 * k) {
            deltas[j] += deltas[j - 1]
            answer = min(answer, deltas[j])
        }
        out.appendln(answer)
    }
    print(out)
}