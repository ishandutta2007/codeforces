import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m) = ints()
    var x = 0
    var y = min(n, 0)
    var st = Array<HashSet<Pair<Int, Int>>>(26) { hashSetOf() }
    while (m-- > 0) {
        var s = strings()
        if (s[0] == "-") {
            var u = s[1].toInt()
            var v = s[2].toInt()
            for (j in 0..25) {
                if (st[j].contains(Pair(v, u))) {
                    x--
                }
                if (st[j].contains(Pair(u, v))) {
                    st[j].remove(Pair(u, v))
                    if (st[j].contains(Pair(v, u))) {
                        y--
                    }
                }
            }
        } else if (s[0] == "+") {
            var u = s[1].toInt()
            var v = s[2].toInt()
            var w = (s[3][0] - 'a')
            st[w].add(Pair(u, v))
            if (st[w].contains(Pair(v, u))) {
                y++
            }
            for (j in 0..25) {
                if (st[j].contains(Pair(v, u))) {
                    x++
                }
            }
        } else {
            var t = s[1].toInt()
            if (t % 2 == 0 && y == 0) {
                cout("NO")
            } else if (t % 2 == 1 && x == 0) {
                cout("NO")
            } else {
                cout("YES")
            }
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