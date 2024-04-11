import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import java.rmi.activation.*
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var (n, l, r) = ints()
        var a = ints()
        a.sort()
        var ans = 0L
        var lo = 0
        var hi = 0
        for (i in 0..n - 1) {
            while (lo != n && a[i] + a[lo] < l) {
                lo++
            }
            while (lo != 0 && a[i] + a[lo - 1] >= l) {
                lo--
            }
            while (hi != 0 && a[i] + a[hi - 1] > r) {
                hi--
            }
            while (hi != n && a[i] + a[hi] <= r) {
                hi++
            }
            ans += maxOf(hi - maxOf(lo, i + 1), 0)
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