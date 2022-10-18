import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (h, w) = ints()
    var a = Array<IntArray>(h) { IntArray(w) }
    var b = Array<IntArray>(h) { IntArray(w) }
    for (i in 0..h - 1) {
        var s = string()
        for (j in 0..w - 1) {
            if (s[j] == 'B') {
                a[i][j] = 1
            }
        }
    }
    for (i in 0..h - 1) {
        for (j in 0..w - 1) {
            if (i != 0) {
                a[i][j] = a[i][j] xor b[i - 1][j]
                b[i][j] = b[i][j] xor b[i - 1][j]
            }
            if (j != 0) {
                a[i][j] = a[i][j] xor b[i][j - 1]
                b[i][j] = b[i][j] xor b[i][j - 1]
            }
            if (i != 0 && j != 0) {
                a[i][j] = a[i][j] xor b[i - 1][j - 1]
                b[i][j] = b[i][j] xor b[i - 1][j - 1]
            }
            if (a[i][j] == 1) {
                b[i][j] = b[i][j] xor 1
            }
        }
    }
    var ans = 0
    for (i in 1..h - 1) {
        for (j in 1..w - 1) {
            if (a[i][j] == 1) {
                a[0][0] = a[0][0] xor 1
                a[0][j] = a[0][j] xor 1
                a[i][0] = a[i][0] xor 1
                ans++
            }
        }
    }
    for (i in 1..h - 1) {
        if (a[i][0] == 1) {
            ans++
            a[0][0] = a[0][0] xor 1
        }
    }
    for (j in 1..w - 1) {
        if (a[0][j] == 1) {
            ans++
            a[0][0] = a[0][0] xor 1
        }
    }
    if (a[0][0] == 1) {
        for (i in 1..h - 1) {
            for (j in 1..w - 1) {
                if (a[i][j] == 1 && a[0][j] == 1 && a[i][0] == 1) {
                    a[0][0] = 0
                }
            }
        }
        ans += a[0][0]
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