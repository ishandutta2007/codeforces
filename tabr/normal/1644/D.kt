import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var (h, w, k, q) = ints()
        var cnt = 0
        var x = IntArray(q)
        var y = IntArray(q)
        for (i in 0..q - 1) {
            var (xx, yy) = ints()
            x[i] = xx
            y[i] = yy
        }
        var sx = HashSet<Int>()
        var sy = HashSet<Int>()
        for (i in q - 1 downTo 0) {
            if (sx.size == h || sy.size == w) {
                break
            }
            if (sx.contains(x[i]) && sy.contains(y[i])) {
                continue
            }
            cnt++
            sx.add(x[i])
            sy.add(y[i])
        }
        var ans = 1
        while (cnt > 0) {
            if (cnt % 2 == 1) {
                ans = ((1L * ans * k) % 998244353).toInt()
            }
            k = ((1L * k * k) % 998244353).toInt()
            cnt /= 2
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