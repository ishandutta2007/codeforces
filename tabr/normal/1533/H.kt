import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (h, w) = ints()
    var a = Array<IntArray>(h) { IntArray(w) }
    for (i in 0..h - 1) {
        var t = string()
        for (j in 0..w - 1) {
            a[i][j] = t[j] - 'A'
        }
    }
    var ans = LongArray(5)
    var fact = IntArray(6)
    var C = Array<IntArray>(6) { IntArray(6) }
    fact[0] = 1
    for (i in 1..5) {
        fact[i] = fact[i - 1] * i
    }
    for (i in 0..5) {
        for (j in 0..i) {
            C[i][j] = fact[i] / fact[j] / fact[i - j]
        }
    }
    for (mask in 1..31) {
        var c = Array<IntArray>(h + 1) { IntArray(w) }
        for (i in 0..h - 1) {
            for (j in 0..w - 1) {
                if ((mask and (1 shl a[i][j])) != 0) {
                    c[i][j] = 1
                }
            }
        }
        var s = 0L
        for (i in 0..h - 1) {
            for (j in w - 2 downTo 0) {
                if (c[i][j] == 1) {
                    c[i][j] += c[i][j + 1]
                }
            }
        }
        for (j in 0..w - 1) {
            var st = IntArray(h + 1)
            var top = -1
            for (i in 0..h) {
                var k = i
                while (top >= 0 && c[st[top]][j] >= c[k][j]) {
                    var tm = c[st[top]][j] - c[k][j]
                    if (top > 0) {
                        tm = c[st[top]][j] - maxOf(c[k][j], c[st[top - 1]][j])
                    }
                    s += 1L * (i - st[top]) * (i - st[top] + 1) / 2 * tm
                    c[st[top]][j] = c[k][j]
                    k = st[top]
                    top--
                }
                top++
                st[top] = k
            }
        }
        var pcnt = 0
        for (i in 0..4) {
            if ((mask and (1 shl i)) != 0) {
                pcnt++
            }
        }
        for (i in pcnt - 1..4) {
            if (i % 2 == pcnt % 2) {
                ans[i] -= s * C[5 - pcnt][i + 1 - pcnt]
            } else {
                ans[i] += s * C[5 - pcnt][i + 1 - pcnt]
            }
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