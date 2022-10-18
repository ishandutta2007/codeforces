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
        var (h, w, k) = ints()
        var s = Array<String>(h) { "" }
        for (i in 0..h - 1) {
            var t = string()
            s[i] = t
        }
        var a = Array<IntArray>(h) { IntArray(w) }
        for (i in 0..h - 1) {
            for (j in 0..w - 1) {
                if (s[i][j] == '.') {
                    continue
                }
                for (l in k..i) {
                    var ok = true
                    if (j + l >= w || j - l < 0) {
                        break
                    }
                    for (x in 0..l) {
                        if (s[i - x][j - x] != '*' || s[i - x][j + x] != '*') {
                            ok = false
                        }
                    }
                    if (ok) {
                        for (x in 0..l) {
                            a[i - x][j - x] = 1
                            a[i - x][j + x] = 1
                        }
                    }
                }
            }
        }
        var ans = "YES"
        for (i in 0..h - 1) {
            for (j in 0..w - 1) {
                if (s[i][j] == '*' && a[i][j] == 0) {
                    ans = "NO"
                }
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