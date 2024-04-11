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
        var ans = Array<IntArray>(n + 1) { IntArray(3) }
        var sz = 0
        for (i in 0..n - 1) {
            var id = i
            for (j in i + 1..n - 1) {
                if (a[id] > a[j]) {
                    id = j
                }
            }
            if (id == i) {
                continue
            }
            ans[sz][0] = i + 1
            ans[sz][1] = n
            ans[sz][2] = id - i
            sz++
            for (j in 1..id - i) {
                var c = a[i]
                for (l in i..n - 2) {
                    a[l] = a[l + 1]
                }
                a[n - 1] = c
            }
        }
        cout(sz)
        for (i in 0..sz - 1) {
            cout(ans[i])
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