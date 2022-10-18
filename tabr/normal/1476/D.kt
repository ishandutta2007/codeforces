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
        var a = IntArray(n)
        for (i in 0..n - 1) {
            if ((s[i] == 'L') == (i % 2 == 0)) {
                a[i] = 1
            }
        }
        var b = IntArray(n)
        b[0] = 1
        for (i in 1..n - 1) {
            if (a[i] == a[i - 1]) {
                b[i] = b[i - 1] + 1
            } else {
                b[i] = 1
            }
        }
        var c = IntArray(n)
        c[n - 1] = 1
        for (i in n - 2 downTo 0) {
            if (a[i] == a[i + 1]) {
                c[i] = c[i + 1] + 1
            } else {
                c[i] = 1
            }
        }
        var ans = IntArray(n + 1)
        for (i in 0..n) {
            if (i != 0) {
                if (s[i - 1] == 'L') {
                    ans[i] += b[i - 1]
                }
            }
            if (i != n) {
                if (s[i] == 'R') {
                    ans[i] += c[i]
                }
            }
            ans[i]++
        }
        cout(ans)
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