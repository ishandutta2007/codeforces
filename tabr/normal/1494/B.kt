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
        var (n, u, r, d, l) = ints()
        var ans = "No"
        var b = listOf<Int>(u, r, d, l)
        for (i in 0..15) {
            var a = IntArray(4)
            for (j in 0..3) {
                if ((i and (1 shl j)) != 0) {
                    a[j]++
                    a[(j + 3) % 4]++
                }
            }
            ans = "Yes"
            for (j in 0..3) {
                if (b[j] - a[j] < 0 || n - 2 < b[j] - a[j]) {
                    ans = "No"
                }
            }
            if (ans == "Yes") {
                break
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