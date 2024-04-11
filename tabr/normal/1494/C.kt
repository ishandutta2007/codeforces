import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var (n, m) = ints()
        var a = ints()
        var b = ints()
        var ans = 0
        for (loop in 0..1) {
            var x = ArrayList<Int>()
            var y = ArrayList<Int>()
            if (loop == 0) {
                for (i in 0..n - 1) {
                    if (a[i] > 0) {
                        break
                    }
                    x.add(-a[i])
                }
                for (i in 0..m - 1) {
                    if (b[i] > 0) {
                        break
                    }
                    y.add(-b[i])
                }
            } else {
                for (i in n - 1 downTo 0) {
                    if (a[i] < 0) {
                        break
                    }
                    x.add(a[i])
                }
                for (i in m - 1 downTo 0) {
                    if (b[i] < 0) {
                        break
                    }
                    y.add(b[i])
                }
            }
            x.reverse()
            y.reverse()
            var c = 0
            var j = x.size - 1
            var t = 0
            for (i in y.size - 1 downTo 0) {
                while (j != -1 && x[j] > y[i]) {
                    j--
                }
                if (j == -1) {
                    break
                }
                var k = j + 1
                var lo = -1
                var hi = i
                while (hi - lo > 1) {
                    var mid = (hi + lo) / 2
                    if (y[mid] < y[i] - k + 1) {
                        lo = mid
                    } else {
                        hi = mid
                    }
                }
                var l = hi
                t = max(t, c + i - l + 1)
                if (x[j] == y[i]) {
                    c++
                }
            }
            t = max(t, c)
            ans += t
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