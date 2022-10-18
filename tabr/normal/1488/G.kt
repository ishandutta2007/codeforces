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
    var s = 0L
    var a = LongArray(n)
    var c = LongArray(n + 1)
    for (i in 1..n) {
        for (j in 2..n) {
            if (i * j > n) {
                break
            }
            c[i * j]++
        }
    }
    for (i in 1..n) {
        a[i - 1] = (n / i - 1).toLong()
        a[i - 1] -= c[i]
    }
    a.sort()
    a.reverse()
    for (i in 1..n - 1) {
        a[i] += a[i - 1]
    }
    var ans = LongArray(n)
    for (i in 0..n - 2) {
        ans[i] = a[n - 2 - i]
    }
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