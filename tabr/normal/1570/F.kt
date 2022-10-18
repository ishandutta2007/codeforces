import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (h, w) = ints()
    var a = Array<IntArray>(h) { IntArray(w) }
    for (i in 0..h - 1) {
        var b = ints()
        for (j in 0..w - 1) {
            a[i][j] = b[j]
        }
    }
    var ans = ArrayList<Pair<Int, Int>>()
    var b = Array<IntArray>(h) { IntArray(w) }
    for (i in 0..h - 2) {
        for (j in 0..w - 2) {
            if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 4) {
                b[i][j] = 1
                b[i + 1][j] = 1
                b[i][j + 1] = 1
                b[i + 1][j + 1] = 1
                ans.add(Pair(i + 1, j + 1))
            }
        }
    }
    var ng = false
    for (i in 0..h - 1) {
        for (j in 0..w - 1) {
            if (a[i][j] != b[i][j]) {
                ng = true
            }
        }
    }
    if (ng) {
        cout(-1)
    } else {
        cout(ans.size)
        for ((x, y) in ans) {
            cout("${x} ${y}")
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