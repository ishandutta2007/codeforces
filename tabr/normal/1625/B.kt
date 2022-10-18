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
        var order = Array<Int>(n) { it }
        order.sortWith(compareBy({ a[it] }, { it }))
        var ans = -1
        var beg = 0
        while (beg < n) {
            var end = beg
            var b = ArrayList<Int>()
            while (end < n && a[order[beg]] == a[order[end]]) {
                b.add(order[end])
                end++
            }
            if (b.size > 1) {
                var front = -1
                for (i in b) {
                    if (front != -1) {
                        ans = maxOf(ans, front + (n - i))
                    }
                    front = i
                }
            }
            beg = end
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