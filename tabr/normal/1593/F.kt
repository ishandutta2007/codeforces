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
        var (n, a, b) = ints()
        var s = string()
        var dp = Array<Array<Array<BooleanArray>>>(n + 1) { Array(a) { Array(b) { BooleanArray(n * 2 + 1) } } }
        dp[0][0][0][n] = true
        for (i in 0..n - 1) {
            var c = s[i] - '0'
            for (x in 0..a - 1) {
                for (y in 0..b - 1) {
                    for (z in 0..2 * n) {
                        if (dp[i][x][y][z]) {
                            var nx = (x * 10 + c) % a
                            var ny = (y * 10 + c) % b
                            dp[i + 1][nx][y][z + 1] = true
                            dp[i + 1][x][ny][z - 1] = true
                        }
                    }
                }
            }
        }
        var t = -1
        for (z in 1..2 * n - 1) {
            if (dp[n][0][0][z] && abs(t - n) > abs(z - n)) {
                t = z
            }
        }
        if (t == -1) {
            cout(-1)
            continue
        }
        var ans = CharArray(n)
        var x = 0
        var y = 0
        for (i in n downTo 1) {
            assert(dp[i][x][y][t])
            var c = s[i - 1] - '0'
            var ok = false
            for (px in 0..a - 1) {
                for (py in 0..b - 1) {
                    if (t > 0 && (px * 10 + c) % a == x && dp[i - 1][px][y][t - 1]) {
                        ans[i - 1] = 'R'
                        x = px
                        t--
                        ok = true
                        break
                    } else if (t < 2 * n && (py * 10 + c) % b == y && dp[i - 1][x][py][t + 1]) {
                        ans[i - 1] = 'B'
                        y = py
                        t++
                        ok = true
                        break
                    }
                }
                if (ok) {
                    break
                }
            }
            assert(ok)
        }
        assert(dp[0][x][y][t])
        cout(ans.joinToString(""))
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