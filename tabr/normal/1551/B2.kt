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
        var (n, k) = ints()
        var a = ints()
        var b = IntArray(n)
        var c = IntArray(n)
        for (i in a) {
            b[i - 1]++
        }
        var ans = IntArray(n)
        var e = ArrayList<Int>()
        for (i in 0..n - 1) {
            if (b[a[i] - 1] < k) {
                e.add(i)
            }
        }
        while (e.size % k != 0) {
            e.removeAt(e.size - 1)
        }
        e.sortWith(compareBy({ a[it] }))
        for (i in 0..e.size - 1) {
            ans[e[i]] = i % k + 1
        }
        var id = 0
        for (i in 0..n - 1) {
            var d = a[i] - 1
            if (b[d] >= k) {
                if (c[d] < k) {
                    c[d]++
                    ans[i] = c[d]
                }
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