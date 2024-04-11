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
        var (n, x) = ints()
        var a = ints()
        var b = IntArray(n + 1)
        for (i in 0..n - 1) {
            b[i + 1] = b[i] + a[i]
        }
        var c = IntArray(n + 1) { -2e9.toInt() }
        c[0] = 0
        for (i in 0..n) {
            for (j in i..n) {
                c[j - i] = maxOf(c[j - i], b[j] - b[i])
            }
        }
        var d = IntArray(n + 1)
        d[n] = c[n]
        for (i in n - 1 downTo 0) {
            d[i] = maxOf(c[i], d[i + 1])
        }
        var ans = IntArray(n + 1)
        ans[0] = d[0]
        for (i in 1..n) {
            ans[i] = maxOf(ans[i - 1], d[i] + x * i)
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