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
        var (h, w, k) = ints()
        var a = h * w / 2
        k = a - k
        if (h % 2 == 1) {
            if (k % 2 == (a - w / 2) % 2 && k <= a - w / 2) {
                cout("YES")
            } else {
                cout("NO")
            }
        } else if (w % 2 == 1) {
            if (k % 2 == h / 2 % 2 && k >= h / 2) {
                cout("YES")
            } else {
                cout("NO")
            }
        } else {
            if (k % 2 == 0) {
                cout("YES")
            } else {
                cout("NO")
            }
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