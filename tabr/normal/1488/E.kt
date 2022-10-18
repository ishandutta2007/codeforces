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
        var n = int()
        var a = ints()
        var b = Array<ArrayList<Int>>(n) { arrayListOf() }
        for (i in 0..n - 1) {
            a[i]--
            b[a[i]].add(i)
        }
        var ans = 1
        var c = IntArray(n + 1) { -1 }
        for (i in 0..n - 1) {
            if (b[a[i]].size == 1) {
                continue
            } else if (b[a[i]][1] == i) {
                continue
            }
            var j = b[a[i]][1]
            var hi = n
            var lo = -1
            while (hi - lo > 1) {
                var mid = (hi + lo) / 2
                if (c[mid] < j) {
                    hi = mid
                } else {
                    lo = mid
                }
            }
            c[hi] = j
            if (i + 1 < j) {
                ans = max(ans, (hi + 1) * 2 + 1)
            } else {
                ans = max(ans, (hi + 1) * 2)
            }
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