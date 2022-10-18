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
        var (n, s) = longs()
        var lo = (s + n - 1) / n
        var hi = 2e18.toLong()
        while (hi - lo > 1) {
            var mid = (hi + lo) / 2
            var x = 0L
            var tmp = mid
            var cnt = 0
            while (tmp > 1 && cnt < n) {
                cnt++
                x += tmp
                tmp = (tmp + 1) / 2
            }
            x += (n - cnt)
            if (x <= s) {
                lo = mid
            } else {
                hi = mid
            }
        }
        cout(lo)
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