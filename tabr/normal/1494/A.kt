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
        var s = string()
        var n = s.length
        if (s[0] == s[n - 1]) {
            cout("No")
            continue
        }
        var t = CharArray(n)
        var u = CharArray(n)
        for (i in n - 1 downTo 0) {
            if (s[i] == s[0]) {
                t[i] = '('
                u[i] = '('
            } else if (s[i] == s[n - 1]) {
                t[i] = ')'
                u[i] = ')'
            } else {
                t[i] = '('
                u[i] = ')'
            }
        }
        var a = 0
        var b = 0
        for (i in 0..n - 1) {
            if (t[i] == '(') {
                a++
            } else {
                a--
            }
            if (u[i] == '(') {
                b++
            } else {
                b--
            }
            if (a < 0) {
                a = -10000000
            }
            if (b < 0) {
                b = -10000000
            }
        }
        if (a == 0 || b == 0) {
            cout("Yes")
        } else {
            cout("No")
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