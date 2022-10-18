import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var a1 = int()
    var a2 = int()
    var k1 = int()
    var k2 = int()
    var n = int()
    var mx = 0
    for (i in 0..a1) {
        for (j in 0..a2) {
            if (i * k1 + j * k2 <= n) {
                mx = maxOf(mx, i + j)
            }
        }
    }
    var mn = 0
    var z = (k1 - 1) * a1 + (k2 - 1) * a2
    mn = maxOf(0, n - z)
    cout("${mn} ${mx}")
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