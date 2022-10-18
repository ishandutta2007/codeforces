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
        var (x, y, a, b) = longs()
        if (a == b) {
            cout(minOf(x, y) / a)
            continue
        }
        var p = (a * x - b * y) / (a * a - b * b)
        p = maxOf(p, 0)
        p = minOf(p, minOf(x / a, y / b))
        var ans = -1L
        for (i in p - 10..p + 10) {
            var j = minOf((x - a * i) / b, (y - b * i) / a)
            if (i >= 0 && j >= 0 && a * i + b * j <= x && a * j + b * i <= y) {
                ans = maxOf(ans, i + j)
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