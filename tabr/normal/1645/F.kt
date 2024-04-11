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
    var a = ints()
    val N = 150001
    var b = IntArray(N)
    for (i in a) {
        b[i - 1]++
    }
    var c = IntArray(N)
    for (i in 0..N - 1) {
        if (i != 0 && c[i - 1] == 0 && b[i] > 0) {
            c[i - 1] = 1
            b[i]--
        }
        if (b[i] > 0 && c[i] == 0) {
            c[i] = 1
            b[i]--
        }
        if (b[i] > 0) {
            c[i + 1] = 1
            b[i]--
        }
    }
    cout(c.sum())
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