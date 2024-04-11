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
        var n = int()
        var a = ints()
        var inf = 1e9.toInt()
        var m = 2001
        var dp = IntArray(m) { inf }
        dp[0] = 0
        for (x in a) {
            var new_dp = IntArray(m) { inf }
            for (i in 0..m - 1) {
                if (i < x) {
                    new_dp[0] = min(new_dp[0], dp[i] + x)
                } else {
                    new_dp[i - x] = min(new_dp[i - x], dp[i] + x)
                }
                if (i + x >= m) {
                    continue
                }
                if (dp[i] < x) {
                    new_dp[i + x] = 0
                } else {
                    new_dp[i + x] = min(new_dp[i + x], dp[i] - x)
                }
            }
            new_dp = dp.also { dp = new_dp }
        }
        var ans = inf
        for (i in 0..m - 1) {
            ans = minOf(ans, i + dp[i])
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