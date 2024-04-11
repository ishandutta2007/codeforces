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
        var q = ints()
        var a = IntArray(n)
        var que = IntArray(n)
        var ptr = 0
        var tail = 0
        var st = TreeSet<Int>()
        for (i in 0..n - 1) {
            if (i == 0 || q[i] != q[i - 1]) {
                a[i] = q[i]
                var c = 1
                if (i != 0) {
                    c = q[i - 1] + 1
                }
                for (j in c..q[i] - 1) {
                    que[tail++] = j
                }
            } else {
                a[i] = que[ptr++]
            }
        }
        cout(a)
        for (i in 0..n - 1) {
            if (i == 0 || q[i] != q[i - 1]) {
                a[i] = q[i]
                var c = 1
                if (i != 0) {
                    c = q[i - 1] + 1
                }
                for (j in q[i] - 1 downTo c) {
                    st.add(j)
                }
            } else {
                a[i] = st.last()
                st.remove(st.last())
            }
        }
        cout(a)
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