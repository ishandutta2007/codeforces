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
    var c = longs()
    var tt = int()
    var q = Array<Triple<Int, Int, Int>>(tt) { Triple(0, 0, 0) }
    for (i in 0..tt - 1) {
        var (l, r) = ints()
        l -= 2
        r--
        q[i] = Triple(l, r, i)
    }
    q.sortWith(compareBy({ it.second }, { it.first }, { it.third }))
    var ans = LongArray(tt)
    var v = ArrayList<Long>()
    var p = ArrayList<Int>()
    var w = ArrayList<Long>()
    var ac = ArrayList<Long>()
    v.add(1e9.toLong())
    p.add(-1)
    w.add(0L)
    ac.add(0L)
    var s = 0L
    var id = 0
    for (i in 0..n - 1) {
        while (v.last() <= c[i]) {
            s -= w.last()
            v.removeLast()
            w.removeLast()
            p.removeLast()
            ac.removeLast()
        }
        v.add(c[i])
        var lp = p.last()
        p.add(i)
        w.add(c[i] * (i - lp))
        ac.add(ac.last() + w.last())
        s += w.last()
        while (id != tt && q[id].second == i) {
            var lo = 0
            var hi = p.size - 1
            var l = q[id].first
            while (hi - lo > 1) {
                var mid = (hi + lo) / 2
                if (p[mid] >= l) {
                    hi = mid
                } else {
                    lo = mid
                }
            }
            var t = s
            t -= ac[lo]
            t -= v[hi] * (l - p[lo])
            ans[q[id].third] = t
            id++
        }
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