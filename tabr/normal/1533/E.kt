import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var n = int()
    var a = ints()
    var b = ints()
    var m = int()
    var c = ints()
    a.sort()
    b.sort()
    var x = IntArray(n + 1)
    var y = IntArray(n + 1)
    for (i in 1..n) {
        x[i] = b[i] - a[i - 1]
    }
    for (i in 0..n - 1) {
        y[i] = b[i] - a[i]
    }
    x[0] = -2e9.toInt()
    y[n] = -2e9.toInt()
    for (i in 1..n) {
        y[i] = maxOf(y[i], y[i - 1])
    }
    for (i in n - 1 downTo 0) {
        x[i] = maxOf(x[i], x[i + 1])
    }
    var ans = IntArray(m)
    for (i in 0..m - 1) {
        if (c[i] < a[0]) {
            ans[i] = maxOf(b[0] - c[i], x[0])
            continue
        }
        var lo = 0
        var hi = n
        while (hi - lo > 1) {
            var mid = (hi + lo) / 2
            if (a[mid] <= c[i]) {
                lo = mid
            } else {
                hi = mid
            }
        }
        ans[i] = b[hi] - c[i]
        ans[i] = maxOf(ans[i], y[lo])
        if (hi != n) {
            ans[i] = maxOf(ans[i], x[hi + 1])
        }
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