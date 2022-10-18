import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m, k) = ints()
    var a = ints()
    a.reverse()
    a.add(k + 1)
    var l = 30
    var to = Array<Array<Int>>(l) { Array<Int>(n + 1) { 0 } }
    var end = 0
    var sum = 0
    to[0][n] = n
    for (beg in 0..n - 1) {
        while (sum + a[end] <= k) {
            sum += a[end]
            end++
        }
        to[0][beg] = end
        sum -= a[beg]
    }
    for (i in 1..l - 1) {
        for (j in 0..n) {
            to[i][j] = to[i - 1][to[i - 1][j]]
        }
    }
    var b = IntArray(n) { it }
    for (i in 0..l - 1) {
        if ((m and (1 shl i)) != 0) {
            var c = IntArray(n)
            for (j in 0..n - 1) {
                c[j] = to[i][b[j]]
            }
            b = c
        }
    }
    cout(b[0])
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