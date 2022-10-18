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
        var s = Array<IntArray>(n) { IntArray(5) }
        for (i in 0..n - 1) {
            var t = string()
            for (c in t) {
                s[i][c - 'a']++
            }
        }
        var ans = 0
        for (x in 0..4) {
            var a = IntArray(n)
            for (i in 0..n - 1) {
                for (j in 0..4) {
                    if (x == j) {
                        a[i] += s[i][j]
                    } else {
                        a[i] -= s[i][j]
                    }
                }
            }
            a.sort()
            a.reverse()
            var t = 0
            var ss = 0
            for (i in a) {
                if (ss + i <= 0) {
                    break
                }
                ss += i
                t++
            }
            ans = maxOf(ans, t)
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