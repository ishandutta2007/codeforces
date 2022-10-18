import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var n = int()
    var a = ints()
    a.sort()
    var beg = 0
    var x = ArrayList<Int>()
    var y = ArrayList<Int>()
    while (beg < n) {
        var end = beg
        while (end < n && a[beg] == a[end]) {
            end++
        }
        if (end - beg > 2) {
            println("NO")
            return
        }
        x.add(a[beg])
        if (end - beg == 2) {
            y.add(a[beg])
        }
        beg = end
    }
    y.reverse()
    cout("YES")
    cout(x.size)
    cout(x)
    cout(y.size)
    cout(y)
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