import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var s = string()
    var n = s.length
    var to0 = Array<IntArray>(n + 2) { IntArray(18) { n + 1 } }
    var to1 = Array<IntArray>(n + 2) { IntArray(18) { n + 1 } }
    for (i in n - 1 downTo 0) {
        to0[i][0] = to0[i + 1][0]
        to1[i][0] = to1[i + 1][0]
        if (s[i] == '0') {
            to0[i][0] = i + 1
        } else {
            to1[i][0] = i + 1
        }
    }
    for (j in 1..17) {
        for (i in 0..n) {
            to0[i][j] = to0[to0[i][j - 1]][j - 1]
            to1[i][j] = to1[to1[i][j - 1]][j - 1]
        }
    }
    var ans = IntArray(n)
    for (i in 1..n) {
        var t = 0
        var pos = 0
        while (pos < n) {
            t++
            var p0 = pos
            for (j in 0..17) {
                if (((i + 1) and (1 shl j)) != 0) {
                    p0 = to0[p0][j]
                }
            }
            var p1 = pos
            for (j in 0..17) {
                if (((i + 1) and (1 shl j)) != 0) {
                    p1 = to1[p1][j]
                }
            }
            pos = maxOf(p0, p1) - 1
        }
        ans[i - 1] = t
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