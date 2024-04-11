import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var (h, w) = ints()
        var a = Array<IntArray>(h) { IntArray(w) }
        var k = 0
        for (i in 0..h - 1) {
            var b = ints()
            for (j in 0..w - 1) {
                a[i][j] = b[j]
                if (b[j] != 0) {
                    k++
                }
            }
        }
        var c = ArrayList<Int>()
        var cnt = 0
        fun dfs(x: Int, y: Int) {
            var b = a[x][y]
            c.add(b)
            a[x][y] = 0
            if (x != 0 && a[x - 1][y] != 0) {
                dfs(x - 1, y)
                c.add(b)
            }
            if (x != h - 1 && a[x + 1][y] != 0) {
                dfs(x + 1, y)
                c.add(b)
            }
            if (y != 0 && a[x][y - 1] != 0) {
                dfs(x, y - 1)
                c.add(b)
            }
            if (y != w - 1 && a[x][y + 1] != 0) {
                dfs(x, y + 1)
                c.add(b)
            }
        }
        for (i in 0..h - 1) {
            for (j in 0..w - 1) {
                if (a[i][j] != 0) {
                    cnt++
                    dfs(i, j)
                }
            }
        }
        if (cnt != 1) {
            cout(-1)
        } else {
            var x = minOf(c.size, k)
            var y = maxOf(0, c.size - k) + 1
            output.append(x).append(" ").appendLine(y)
            for (i in 0..y - 1) {
                var b = IntArray(x)
                for (j in i..i + x - 1) {
                    b[j - i] = c[j]
                }
                cout(b)
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