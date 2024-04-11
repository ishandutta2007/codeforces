import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var n = int()
        var a = LongArray(n)
        var b = LongArray(n)
        var g = Array<ArrayList<Int>>(n) { ArrayList() }
        var p = Array<IntArray>(20) { IntArray(n) }
        for (i in 1..n - 1) {
            var (pp, aa, bb) = ints()
            pp--
            g[pp].add(i)
            p[0][i] = pp
            a[i] = aa.toLong()
            b[i] = bb.toLong()
        }
        for (i in 1..19) {
            for (j in 0..n - 1) {
                p[i][j] = p[i - 1][p[i - 1][j]]
            }
        }
        var depth = IntArray(n)
        fun Dfs(v: Int, p: Int) {
            for (to in g[v]) {
                if (to == p) {
                    continue
                }
                depth[to] = depth[v] + 1
                a[to] += a[v]
                b[to] += b[v]
                Dfs(to, v)
            }
        }
        Dfs(0, -1)
        var ans = IntArray(n - 1)
        for (i in 1..n - 1) {
            var high = n
            var low = -1
            while (high - low > 1) {
                var mid = (high + low) / 2
                var t = i
                for (j in 0..19) {
                    if ((mid and (1 shl j)) != 0) {
                        t = p[j][t]
                    }
                }
                if (b[t] <= a[i]) {
                    high = mid
                } else {
                    low = mid
                }
            }
            ans[i - 1] = depth[i] - high
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