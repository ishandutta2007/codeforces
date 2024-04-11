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
    var a = longs()
    var s = a.sum()
    var ans = ArrayList<Int>()
    var c = IntArray(1001000)
    for (i in 0..n - 1) {
        c[a[i].toInt()]++
    }
    for (i in 0..n - 1) {
        var t = s - a[i]
        if (t % 2 == 1L) {
            continue
        }
        t /= 2
        var d = 1
        if (t == a[i]) {
            d++
        }
        if (t < 1001000L && c[t.toInt()] >= d) {
            ans.add(i + 1)
        }
    }
    cout(ans.size)
    cout(ans)
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