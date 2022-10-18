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
        var (n, k) = ints()
        var a = ints()
        var g = Array<ArrayList<Int>>(n) { ArrayList<Int>() }
        for (i in 0..n - 2) {
            var (x, y) = ints()
            x--
            y--
            g[x].add(y)
            g[y].add(x)
        }
        var b = 0
        for (i in a) {
            b = b xor i
        }
        var ans = "NO"
        var dp = IntArray(n)
        var ok = IntArray(n)
        fun dfs(v: Int, p: Int) {
            dp[v] = a[v]
            for (to in g[v]) {
                if (to == p) {
                    continue
                }
                dfs(to, v)
                dp[v] = dp[v] xor dp[to]
                ok[v] += ok[to]
            }
            if (b == 0 && dp[v] == 0) {
                ans = "YES"
            }
            if (k > 2 && ok[v] > 1) {
                ans = "YES"
            }
            if (k > 2 && dp[v] == b) {
                ok[v] = 1
            }
            if (k > 2 && dp[v] == 0 && ok[v] == 1) {
                ans = "YES"
            }
        }
        dfs(0, -1)
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