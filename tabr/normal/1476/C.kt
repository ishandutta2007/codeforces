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
        var c = longs()
        var a = longs()
        var b = longs()
        var cur = (abs(a[1] - b[1]) + 2)
        var ans = 0L
        a.add(-1)
        b.add(-1)
        for (i in 2..n) {
            ans = max(cur + c[i - 1] - 1, ans)
            if (a[i] == b[i]) {
                cur = 2L
            } else {
                cur += c[i - 1] + 1 - abs(a[i] - b[i])
                cur = max(cur, abs(a[i] - b[i]) + 2)
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