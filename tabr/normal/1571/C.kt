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
        var mx = 1e9.toInt()
        var mn = 0
        while (n-- > 0) {
            var (s, t, r) = strings()
            s = s.reversed()
            t = t.reversed()
            var l = minOf(s.length, t.length)
            var k = 0
            for (i in 0..l - 1) {
                if (s[i] == t[i]) {
                    k = i + 1
                } else {
                    break
                }
            }
            if (r == "0") {
                mn = maxOf(mn, k + 1)
            } else {
                mx = minOf(mx, k)
            }
        }
        var ans = mx - mn + 1
        if (ans < 0) {
            cout(0)
        } else {
            cout(ans)
            var a = IntArray(ans) { it + mn }
            cout(a)
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