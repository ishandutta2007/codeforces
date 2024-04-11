import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var n = readint()
        var a = readlongs()
        var ans = ArrayList<Int>()
        var b = Array<Pair<Int, Long>>(n) { it -> Pair(it, a[it]) }
        b.sortWith(compareBy({ it.second }, { it.first }))
        var lo = -1
        var hi = n - 1
        while (hi - lo > 1) {
            var mid = (hi + lo) / 2
            var s = 0L
            for (i in 0..n - 1) {
                if (i <= mid) {
                    s += b[i].second
                } else {
                    if (s >= b[i].second) {
                        s += b[i].second
                    } else {
                        s = -1L
                        break
                    }
                }
            }
            if (s == -1L) {
                lo = mid
            } else {
                hi = mid
            }
        }
        for (i in hi..n - 1) {
            ans.add(b[i].first + 1)
        }
        ans.sort()
        cout(ans.size)
        cout(ans.joinToString(" "))
    }
    println(output)
}

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendLine(s)
fun cout(s: Int) = output.appendLine(s.toString())
fun cout(s: Long) = output.appendLine(s.toString())
fun assert(x: Boolean) {
    if (!x) throw AssertionError()
}