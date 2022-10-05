import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val answer = IntArray(n + 1) { Int.MAX_VALUE }
        var last = 0
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            val k = tokenizer.nextToken().toInt()
            if (answer[k] == Int.MAX_VALUE) {
                answer[k] = if (j == 1) 0 else 1
            } else {
                if (last != k) {
                    answer[k]++
                }
            }
            last = k
        }
        for (k in 1..n) {
            if (k != last && answer[k] != Int.MAX_VALUE) {
                answer[k]++
            }
        }
        out.appendln(answer.min())
    }
    print(out)
}