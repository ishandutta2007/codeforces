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
        var r = longs()
        var c = longs()
        r.add(1)
        c.add(1)
        n++
        var p = Array<Pair<Long, Long>>(n) { Pair(r[it], c[it]) }
        p.sortWith(compareBy({ it.first }))
        var ans = 0L
        for (i in 0..n - 2) {
            if (p[i] == p[i + 1]) {
                continue
            }
            var q = p[i].first + p[i].second
            var x = p[i + 1].first - p[i].first
            var y = p[i + 1].second - p[i].second
            if (q % 2 == 0L) {
                if (x == y) {
                    ans += x
                } else {
                    ans += (x - y) / 2
                }
            } else {
                ans += (x - y + 1) / 2
            }
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