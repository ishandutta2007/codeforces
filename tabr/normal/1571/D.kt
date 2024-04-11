import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m) = ints()
    var a = Array<IntArray>(n) { IntArray(n) }
    var b = IntArray(n)
    var c = IntArray(n)
    var xx = -1
    var yy = -1
    for (i in 0..m - 1) {
        var (x, y) = ints()
        x--
        y--
        if (i == 0) {
            xx = x
            yy = y
        }
        a[x][y]++
        b[x]++
        c[y]++
    }
    var ans = 1
    for (i in 0..n - 1) {
        for (j in 0..n - 1) {
            if (i == j) {
                continue
            }
            if (xx == i && yy == j) {
                continue
            }
            if (xx != i && yy != j) {
                ans = maxOf(ans, b[i] + c[j] - a[i][j] + 1)
            } else {
                ans = maxOf(ans, a[i][j] + 1)
            }
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