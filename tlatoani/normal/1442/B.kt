import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val ay = jin.readLine().split(" ").map { it.toInt() }
        val time = IntArray(n + 1)
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..k) {
            time[tokenizer.nextToken().toInt()] = j
        }
        var answer = 1L
        for (j in 0 until n) {
            if (time[ay[j]] != 0) {
                var pos = 0L
                if (j > 0 && time[ay[j - 1]] < time[ay[j]]) {
                    pos++
                }
                if (j < n - 1 && time[ay[j + 1]] < time[ay[j]]) {
                    pos++
                }
                answer *= pos
                answer %= MOD
            }
        }
        out.appendln(answer)
    }
    print(out)
}