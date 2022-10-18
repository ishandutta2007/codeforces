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
        var ans = ArrayList<Pair<Int, Int>>()
        var st = sortedSetOf(compareBy<Pair<Int, Int>>({ it.first }, { it.second }))
        for (i in 0..n - 1) {
            st.add(Pair(a[i], i + 1))
        }
        while (st.last().first != 0) {
            var p = st.last()
            st.remove(p)
            var q = st.last()
            st.remove(q)
            if (q.first == 0) {
                break
            }
            var np = Pair(p.first - 1, p.second)
            var nq = Pair(q.first - 1, q.second)
            st.add(np)
            st.add(nq)
            ans.add(Pair(p.second, q.second))
        }
        cout(ans.size)
        for (p in ans) {
            cout("${p.first} ${p.second}")
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