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
        var s = string()
        var a = Array<ArrayList<Int>>(26) { arrayListOf() }
        for (i in 0..s.length - 1) {
            a[s[i] - 'a'].add(i)
        }
        var ans = ""
        var t = 0
        var p = IntArray(26)
        for (i in 0..25) {
            if (!a[i].isEmpty()) {
                t++
                p[i] = 1
            }
        }
        var pos = -1
        for (i in t - 1 downTo 0) {
            for (j in 25 downTo 0) {
                if (p[j] == 1) {
                    var k = pos
                    for (l in 0..a[j].size - 1) {
                        if (a[j][l] > pos) {
                            k = a[j][l]
                            break
                        }
                    }
                    var u = 0
                    for (l in 0..25) {
                        if (l == j) {
                            continue
                        }
                        if (p[l] == 1 && a[l].last() > k) {
                            u++
                        }
                    }
                    if (u == i) {
                        ans += 'a' + j
                        p[j] = 0
                        pos = k
                        break
                    }
                }
            }
            assert(t - i == ans.length)
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