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
        var n = int()
        var c = longs()
        var d = LongArray(n)
        var s = LongArray(n)
        var ans = 1e18.toLong()
        for (i in 0..n - 1) {
            d[i] = c[i]
            s[i] = c[i]
            if (i >= 2) {
                d[i] = min(d[i], d[i - 2])
                s[i] += s[i - 2]
            }
        }
        for (i in 1..n - 1) {
            ans = min(ans, s[i] + d[i] * (n - (i + 2) / 2) + s[i - 1] + d[i - 1] * (n - (i + 1) / 2))
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