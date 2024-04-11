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
        var l = s.length
        var ans = l + 1
        for (i in l - 1 downTo 0) {
            if (s[i] == '0') {
                for (j in i - 1 downTo 0) {
                    if (s[j] == '5' || s[j] == '0') {
                        ans = minOf(ans, l - j - 2)
                        break
                    }
                }
            } else if (s[i] == '5') {
                for (j in i - 1 downTo 0) {
                    if (s[j] == '7' || s[j] == '2') {
                        ans = minOf(ans, l - j - 2)
                        break
                    }
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