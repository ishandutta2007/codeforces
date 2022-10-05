import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val q = tokenizer.nextToken().toInt()
    val s = jin.readLine()
    val sums = Array(2) { IntArray(n + 1) }
    for (j in 1..n) {
        sums[0][j] = sums[0][j - 1]
        sums[1][j] = sums[1][j - 1]
        if (j == n || s[j - 1] == s[j]) {
            sums[s[j - 1] - '0'][j]++
        }
    }
    val out = StringBuilder()
    repeat(q) {
        val tokenizer = StringTokenizer(jin.readLine())
        val l = tokenizer.nextToken().toInt() - 1
        val r = tokenizer.nextToken().toInt()
        var sum0 = sums[0][r] - sums[0][l]
        var sum1 = sums[1][r] - sums[1][l]
        if (r == n || s[r - 1] == s[r]) {
            if (s[r - 1] == '0') {
                sum0--
            } else {
                sum1--
            }
        }
        out.appendln(max(sum0, sum1) + 1)
    }
    print(out)
}