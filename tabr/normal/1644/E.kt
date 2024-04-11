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
        var s = string()
        var a = IntArray(s.length)
        for (i in 0..s.length - 1) {
            if (s[i] != s[0]) {
                a[i] = 1
            }
        }
        var x = 0
        var y = 0
        for (i in a) {
            if (i == 0) {
                x++
            } else {
                y++
            }
        }
        if (x == 0 || y == 0) {
            cout(n)
            continue
        }
        var ans = 1L * n * (n - x + 1)
        var now = n
        var m = a.size
        for (i in 1..m - 1) {
            if (a[i] == 0) {
                ans += now
            } else {
                now--
            }
        }
        now = n - 1
        for (i in 0..m - 1) {
            if (a[i] == 0) {
                ans -= now
            } else if (a[i] == 1 && now == n - 1) {
                now = y - 1
            } else {
                now--
            }
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