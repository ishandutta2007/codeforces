import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var (n, k) = ints()
        var a = ints()
        for (i in 0..n - 1) {
            a[i] = i - a[i] + 1
        }
        var inf = 1e9.toInt()
        var dp = Array<IntArray>(n + 1) { IntArray(n + 1) { -inf } }
        dp[0][0] = 0
        for (i in 0..n - 1) {
            for (j in 0..i) {
                dp[i + 1][j + 1] = maxOf(dp[i + 1][j + 1], dp[i][j])
                if (a[i] == j) {
                    dp[i + 1][j] = maxOf(dp[i + 1][j], dp[i][j] + 1)
                } else {
                    dp[i + 1][j] = maxOf(dp[i + 1][j], dp[i][j])
                }
            }
        }
        var ans = -1
        for (i in 0..n) {
            if (dp[n][i] >= k) {
                ans = i
                break
            }
        }
        cout(ans)
    }
    print(output)
}

fun string() = input.readLine()
fun int() = string().toInt()
fun long() = string().toLong()
fun strings() = ArrayList(string().split(" "))
fun ints() = ArrayList(string().split(" ").map { it.toInt() })
fun longs() = ArrayList(string().split(" ").map { it.toLong() })
fun cout(s: String) = output.appendLine(s)
fun <T> cout(s: T) = output.appendLine(s.toString())
fun cout(s: IntArray) = output.appendLine(s.joinToString(" "))
fun cout(s: LongArray) = output.appendLine(s.joinToString(" "))
fun <T> cout(s: Array<T>) = output.appendLine(s.joinToString(" "))
fun <T> cout(s: Iterable<T>) = output.appendLine(s.joinToString(" "))
fun assert(x: Boolean) {
    if (!x) throw AssertionError()
}