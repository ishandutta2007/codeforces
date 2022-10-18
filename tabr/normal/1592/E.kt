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
    var m = 20
    var b = IntArray(n + 1)
    for (i in 0..n - 1) {
        b[i + 1] = b[i] xor a[i]
    }
    var ans = 0
    for (x in 0..m - 1) {
        var beg = 0
        while (beg < n) {
            var end = beg
            while (end < n && ((a[end] and (1 shl x)) != 0)) {
                end++
            }
            if (beg == end) {
                beg++
                continue
            }
            var s = mutableMapOf<Int, Int>()
            for (i in beg..end) {
                if (s[(b[i] shr x)] != null) {
                    ans = maxOf(ans, i - s[(b[i] shr x)]!!)
                } else {
                    s[(b[i] shr x)] = i
                }
            }
            beg = end
        }
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