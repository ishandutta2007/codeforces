import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var t = string()
        var n = int()
        var s = Array<String>(n) { "" }
        for (i in 0..n - 1) {
            s[i] = string()
        }
        var m = t.length
        var ans = ArrayList<Pair<Int, Int>>()
        var last = -1
        var beg = -1
        var end = -1
        var id = -1
        for (i in 0..m - 1) {
            for (j in 0..n - 1) {
                if (i + s[j].length > end && t.substring(i, min(m, i + s[j].length)) == s[j]) {
                    beg = i
                    end = i + s[j].length - 1
                    id = j
                }
            }
            if (last < i) {
                if (end <= last) {
                    ans.clear()
                    break
                }
                ans.add(Pair(id, beg))
                last = end
            }
        }
        if (ans.isEmpty()) {
            cout(-1)
            continue
        }
        cout(ans.size)
        for ((x, y) in ans) {
            cout("${x + 1} ${y + 1}")
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