import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, l, k) = ints()
    var d = ints()
    var a = ints()
    d.add(l)
    var inf = 1e18.toLong()
    var dp = Array<LongArray>(n + 1) { LongArray(k + 1) { inf } }
    dp[0][0] = 0
    for (i in 0..n - 1) {
        for (j in i + 1..n) {
            for (x in 0..k - j + i + 1) {
                var y = x + j - i - 1
                var dist = d[j] - d[i]
                dp[j][y] = minOf(dp[j][y], dp[i][x] + dist * a[i])
            }
        }
    }
    var ans = inf
    for (i in 0..k) {
        ans = minOf(ans, dp[n][i])
    }
    cout(ans)
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