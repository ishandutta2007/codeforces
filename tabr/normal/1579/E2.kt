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
        var b = a.toSet().toIntArray()
        b.sort()
        for (i in 0..n - 1) {
            a[i] = b.binarySearch(a[i])
        }
        var ans = 0L
        var ft = fenwick(b.size + 3)
        for (i in 0..n - 1) {
            var v = ft.get(a[i])
            var w = ft.get(b.size + 2) - ft.get(a[i] + 1)
            ans += minOf(v, w)
            ft.add(a[i] + 1, 1)
        }
        cout(ans)
    }
    print(output)
}

class fenwick(_n: Int) {
    val n = _n
    val node = LongArray(n)
    fun add(_x: Int, v: Long) {
        var x = _x
        while (x < n) {
            node[x] += v
            x = (x or (x + 1))
        }
    }

    fun get(_x: Int): Long {
        var x = _x
        var v = 0L
        while (x >= 0) {
            v += node[x]
            x = (x and (x + 1)) - 1
        }
        return v
    }
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