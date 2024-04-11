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
        var (n, m) = ints()
        var s = string()
        var ax = IntArray(n + 1)
        var an = IntArray(n + 1)
        var bx = IntArray(n + 1)
        var bn = IntArray(n + 1)
        var c = 0
        var d = IntArray(n + 1)
        for (i in 0..n - 1) {
            if (s[i] == '+') {
                c++
            } else {
                c--
            }
            d[i + 1] = c
            ax[i + 1] = max(ax[i], c)
            an[i + 1] = min(an[i], c)
        }
        c = 0
        for (i in n - 1 downTo 0) {
            if (s[i] == '-') {
                c++
            } else {
                c--
            }
            bx[i] = max(bx[i + 1], c)
            bn[i] = min(bn[i + 1], c)
        }
        for (i in 0..m - 1) {
            var (l, r) = ints()
            l--
            var e = d[n] - d[r] + d[l]
            cout(max(ax[l], e + bx[r]) - min(an[l], e + bn[r]) + 1)
        }
    }
    print(output)
}

fun string() = input.readLine()
fun int() = string().toInt()
fun long() = string().toLong()
fun strings() = ArrayList(string().split(" "))
fun ints() = ArrayList(strings().map { it.toInt() })
fun longs() = ArrayList(strings().map { it.toLong() })
fun cout(s: String) = output.appendLine(s)
fun <T> cout(s: T) = output.appendLine(s.toString())
fun cout(s: IntArray) = output.appendLine(s.joinToString(" "))
fun cout(s: LongArray) = output.appendLine(s.joinToString(" "))
fun <T> cout(s: Array<T>) = output.appendLine(s.joinToString(" "))
fun <T> cout(s: Iterable<T>) = output.appendLine(s.joinToString(" "))
fun assert(x: Boolean) {
    if (!x) throw AssertionError()
}