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
        var (n, d) = ints()
        var a = ints()
        var que = ArrayDeque<Int>()
        var inf = 1e9.toInt()
        var b = IntArray(n) { inf }
        for (i in 0..n - 1) {
            if (a[i] == 0) {
                que.addFirst(i)
                b[i] = 0
            }
        }
        while (que.isNotEmpty()) {
            var v = que.first
            que.removeFirst()
            var to = v + d
            if (to >= n) {
                to -= n
            }
            if (b[to] > b[v] + 1) {
                b[to] = b[v] + 1
                que.addLast(to)
            }
        }
        if (b.maxOrNull()!! != inf) {
            cout(b.maxOrNull()!!)
        } else {
            cout(-1)
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