import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var s = string()
        var a = Array(s.length + 1) { IntArray(s.length + 1) }
        a[0][0] = 1
        for (i in 0..s.length - 1) {
            if (s[i] != ')') {
                for (j in 0..s.length - 1) {
                    if (a[i][j] == 1) {
                        a[i + 1][j + 1] = 1
                    }
                }
            }
            if (s[i] != '(') {
                for (j in 1..s.length) {
                    if (a[i][j] == 1) {
                        a[i + 1][j - 1] = 1
                    }
                }
            }
        }
        if (a[s.length][0] == 1) {
            cout("YES")
        } else {
            cout("NO")
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