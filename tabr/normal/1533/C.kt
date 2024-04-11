import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var (n, k) = ints()
        var s = string()
        var c = 0
        for (i in 0..n - 1) {
            if (s[i] == '1') {
                c++
            }
        }
        if (c == 0) {
            cout(0)
            continue
        }
        var a = IntArray(n)
        a[0] = 1
        if (s[0] == '1') {
            c--
        }
        var i = 0
        while (c > 0) {
            var d = k
            while (d > 0) {
                i++
                if (i == n) {
                    i = 0
                }
                if (a[i] == 0) {
                    d--
                }
            }
            a[i] = 1
            if (s[i] == '1') {
                c--
            }
        }
        cout(a.sum())
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