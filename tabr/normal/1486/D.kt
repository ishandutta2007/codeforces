import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, k) = ints()
    var a = ints()
    var lo = 1
    var hi = n + 1
    while (hi - lo > 1) {
        var mid = (hi + lo) / 2
        var ok = false
        var b = IntArray(n)
        var c = IntArray(n)
        for (i in 0..n - 1) {
            if (a[i] >= mid) {
                b[i] = 1
            } else {
                b[i] = -1
            }
            if (i != 0) {
                b[i] += b[i - 1]
            }
        }
        for (i in 0..n - 1) {
            c[i] = min(0, b[i])
            if (i != 0) {
                c[i] = min(c[i], c[i - 1])
            }
        }
        if (b[k - 1] > 0) {
            ok = true
        }
        for (i in k..n - 1) {
            if (b[i] - c[i - k] > 0) {
                ok = true
            }
        }
        if (ok) {
            lo = mid
        } else {
            hi = mid
        }
    }
    cout(lo)
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