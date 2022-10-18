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
        string()
        var (n, m) = ints()
        var b = Array<IntArray>(n) { IntArray(m) }
        for (i in 0..n - 1) {
            var s = string()
            for (j in 0..m - 1) {
                b[i][j] = s[j] - '0'
            }
        }
        var sa = string()
        var a = IntArray(m)
        for (i in 0..m - 1) {
            a[i] = sa[i] - '0'
        }
        if (m == 1) {
            cout(-1)
            continue
        }
        var dp2 = IntArray(100) { -1 }
        var dp3 = IntArray(1000) { -1 }
        for (i in 0..n - 1) {
            for (j in 0..m - 2) {
                var x = b[i][j] * 10 + b[i][j + 1]
                dp2[x] = m * i + j
            }
            for (j in 0..m - 3) {
                var x = b[i][j] * 100 + b[i][j + 1] * 10 + b[i][j + 2]
                dp3[x] = m * i + j
            }
        }
        var ok = BooleanArray(m + 1)
        ok[0] = true
        for (i in 0..m) {
            if (!ok[i]) {
                continue
            }
            if (i + 2 <= m && dp2[a[i] * 10 + a[i + 1]] != -1) {
                ok[i + 2] = true
            }
            if (i + 3 <= m && dp3[a[i] * 100 + a[i + 1] * 10 + a[i + 2]] != -1) {
                ok[i + 3] = true
            }
        }
        if (!ok[m]) {
            cout(-1)
            continue
        }
        var ans = ArrayList<String>()
        var now = m
        while (now > 0) {
            if (now - 2 >= 0 && ok[now - 2]) {
                now -= 2
                var x = dp2[a[now] * 10 + a[now + 1]] / m
                var y = dp2[a[now] * 10 + a[now + 1]] % m
                ans.add("${y + 1} ${y + 2} ${x + 1}")
            } else if (now - 3 >= 0 && ok[now - 3]) {
                now -= 3
                var x = dp3[a[now] * 100 + a[now + 1] * 10 + a[now + 2]] / m
                var y = dp3[a[now] * 100 + a[now + 1] * 10 + a[now + 2]] % m
                ans.add("${y + 1} ${y + 3} ${x + 1}")
            } else {
                assert(false)
            }
        }
        cout(ans.size)
        for (i in ans.size - 1 downTo 0) {
            cout(ans[i])
        }
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