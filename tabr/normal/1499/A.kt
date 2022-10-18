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
        var (n, k1, k2) = ints()
        var (w, b) = ints()
        var x = 0
        var y = 0
        if (k1 > k2) {
            k1 = k2.also { k2 = k1 }
        }
        for (i in 0..n - 1) {
            if (i < k1) {
                x++
            } else if (i >= k2) {
                y++
            } else {
                if ((i - k1) % 2 == 1) {
                    y++
                }
                if ((k2 - i) % 2 == 0) {
                    x++
                }
            }
        }
        if (x >= w && y >= b) {
            cout("YES")
        } else {
            cout("NO")
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