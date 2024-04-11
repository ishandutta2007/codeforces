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
    var a = IntArray(n)
    var b = IntArray(n)
    var s = string()
    for (i in 0..n - 1) {
        a[i] = (s[i] - 'a').toInt()
    }
    s = string()
    for (i in 0..n - 1) {
        b[i] = (s[i] - 'a').toInt()
    }
    var c = IntArray(n)
    for (i in 0..n - 1) {
        c[i] = a[i] + b[i]
    }
    for (i in n - 1 downTo 1) {
        if (c[i] >= 26) {
            c[i] -= 26
            c[i - 1]++
        }
    }
    for (i in 0..n - 1) {
        if (c[i] % 2 == 0) {
            c[i] /= 2
        } else {
            c[i + 1] += 26
            c[i] /= 2
        }
    }
    for (i in 0..n - 1) {
        output.append(('a' + c[i]).toChar())
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