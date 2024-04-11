import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var n = int()
        var s = string()
        var a = string()
        var b = IntArray(n)
        for (i in 0..n - 1) {
            if (s[i] == '(') {
                b[i] = 0
            } else {
                b[i] = 1
            }
        }
        var inf = 1e9.toInt()
        var dp = IntArray(8)
        for (i in 0..7) {
            var c = IntArray(3)
            c[0] = i and 1
            c[1] = (i and 2) / 2
            c[2] = (i and 4) / 4
            for (j in 0..2) {
                if (c[j] != b[j]) {
                    dp[i]++
                }
            }
        }
        for (i in 0..n - 4) {
            var new_dp = IntArray(8) { inf }
            if (a[i] == '1') {
                for (x in 0..7) {
                    var nx = x + 8
                    if (nx == 10 || nx == 12) {
                        var c = 0
                        if (b[i + 3] != 1) {
                            c = 1
                        }
                        new_dp[nx / 2] = minOf(new_dp[nx / 2], dp[x] + c)
                    }
                }
            } else {
                for (x in 0..7) {
                    var nx = x + 8
                    var c = 1 - b[i + 3]
                    new_dp[nx / 2] = minOf(new_dp[nx / 2], dp[x] + c)
                    nx -= 8
                    c = 1 - c
                    new_dp[nx / 2] = minOf(new_dp[nx / 2], dp[x] + c)
                }
            }
            dp = new_dp
        }
        var ans = dp.minOrNull()!!
        if (ans == inf) {
            ans = -1
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