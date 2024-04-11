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
    var s = Array<String>(n) { "" }
    for (i in 0..n - 1) {
        var t = string()
        s[i] = t
    }
    s.sortWith(compareBy({ it.length }))
    var ans = "YES"
    for (i in 1..n - 1) {
        var ok = false
        for (j in 0..s[i].length - s[i - 1].length) {
            if (s[i].substring(j, j + s[i - 1].length) == s[i - 1]) {
                ok = true
                break
            }
        }
        if (!ok) {
            ans = "NO"
            break
        }
    }
    cout(ans)
    if (ans == "YES") {
        for (t in s) {
            cout(t)
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