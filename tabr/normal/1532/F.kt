import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var n = int()
    var s = ArrayList<String>()
    for (i in 0..2 * n - 3) {
        var t = string()
        s.add(t)
    }
    var x = IntArray(n - 1) { -1 }
    var y = IntArray(n - 1) { -1 }
    for (i in 0..2 * n - 3) {
        var l = s[i].length - 1
        if (x[l] == -1) {
            x[l] = i
        } else {
            y[l] = i
        }
    }
    for (z in 0..1) {
        var ok = 1
        for (i in 0..n - 3) {
            if (s[x[n - 2]].substring(0, i + 1) != s[x[i]]) {
                x[i] = y[i].also { y[i] = x[i] }
            }
            if (s[x[n - 2]].substring(0, i + 1) != s[x[i]] || s[y[n - 2]].substring(n - 2 - i, n - 1) != s[y[i]]) {
                ok = 0
                break
            }
        }
        if (ok == 0) {
            x[n - 2] = y[n - 2].also { y[n - 2] = x[n - 2] }
            continue
        }
        var ans = CharArray(2 * n - 2)
        for (i in 0..n - 2) {
            ans[x[i]] = 'P'
            ans[y[i]] = 'S'
        }
        cout(ans.joinToString(""))
        break
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