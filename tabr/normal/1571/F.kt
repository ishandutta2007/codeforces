import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m) = ints()
    var a = ArrayList<Pair<Int, Int>>()
    var ans = IntArray(n)
    var d = 0
    var s = 0
    var ck = IntArray(n) { -1 }
    for (i in 1..n) {
        var (k, t) = ints()
        if (t == 2) {
            a.add(Pair(k, i))
            s += k
            ck[i - 1] = k
        } else {
            ans[i - 1] = d + 1
            d += k
        }
    }
    var k = a.size
    var dp = Array<IntArray>(k + 1) { IntArray(m + 10) { 0 } }
    dp[0][0] = 1
    for (i in 0..k - 1) {
        for (j in 0..m + 5 - a[i].first) {
            if (dp[i][j] == 0) {
                continue
            }
            dp[i + 1][j] = 1
            dp[i + 1][j + a[i].first] = 1
        }
    }
    var id = -1
    for (i in 0..m) {
        if (dp[k][i] == 1 && d + 2 * i - 1 <= m && d + 1 + 2 * (s - i) - 1 <= m) {
            id = i
            break
        }
    }
    if (id == -1 || d > m) {
        cout(-1)
        print(output)
        return
    }
    var x = ArrayList<Int>()
    var y = ArrayList<Int>()
    for (i in k downTo 1) {
        if (id >= a[i - 1].first && dp[i - 1][id - a[i - 1].first] == 1) {
            x.add(a[i - 1].second)
            id -= a[i - 1].first
        } else {
            y.add(a[i - 1].second)
        }
    }
    assert(id == 0)
    var nd = d
    for (i in x) {
        ans[i - 1] = nd + 1
        nd += ck[i - 1] * 2
    }
    nd = d + 1
    for (i in y) {
        ans[i - 1] = nd + 1
        nd += ck[i - 1] * 2
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