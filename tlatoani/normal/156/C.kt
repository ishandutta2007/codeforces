import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 1000000007L

fun main() {
    val choose = Array(2601) { LongArray(101) }
    choose[0][0] = 1L
    for (k in 1..2600) {
        choose[k][0] = 1
        for (j in 1..100) {
            choose[k][j] = (choose[k - 1][j] + choose[k - 1][j - 1]) % MOD
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        val n = s.length
        val k = s.sumBy { it - 'a' }
        var answer = 0L
        for (lambda in 0..k / 26) {
            answer += (if (lambda % 2 == 0) 1L else -1L) * choose[n][lambda] * choose[k - (26 * lambda) + n - 1][n - 1]
            answer %= MOD
        }
        answer += MOD - 1L
        answer %= MOD
        out.appendln(answer)
    }
    print(out)
}