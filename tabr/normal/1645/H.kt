import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var n = int()
    var a = ints()
    var dp_inc = IntArray(n + 1) { 222222 }
    var dp_dec = IntArray(n + 1) { -2 }
    dp_inc[0] = -2
    dp_dec[0] = 222222
    var pre_inc = IntArray(n + 1) { -1 }
    var pre_dec = IntArray(n + 1) { -1 }
    // x -> increase, y -> decrease
    // (x.last(), y.last()) -> (dp_inc[i + 1], a[i]) or (a[i], dp_dec[i + 1])
    for (i in 0..n - 1) {
        // (X, a[i - 1]) -> (X, a[i])
        if (i == 0 || a[i - 1] > a[i]) {
            if (dp_inc[i + 1] > dp_inc[i]) {
                dp_inc[i + 1] = dp_inc[i]
                pre_inc[i + 1] = 0
            }
        }
        // (a[i - 1], X) -> (a[i - 1], a[i])
        if (i != 0 && dp_dec[i] > a[i]) {
            if (dp_inc[i + 1] > a[i - 1]) {
                dp_inc[i + 1] = a[i - 1]
                pre_inc[i + 1] = 1
            }
        }
        // (a[i - 1], X) -> (a[i], X)
        if (i == 0 || a[i - 1] < a[i]) {
            if (dp_dec[i + 1] < dp_dec[i]) {
                dp_dec[i + 1] = dp_dec[i]
                pre_dec[i + 1] = 1
            }
        }
        // (X, a[i - 1]) -> (a[i], a[i - 1])
        if (i != 0 && dp_inc[i] < a[i]) {
            if (dp_dec[i + 1] < a[i - 1]) {
                dp_dec[i + 1] = a[i - 1]
                pre_dec[i + 1] = 0
            }
        }
    }
    if (dp_inc[n] == 222222 && dp_dec[n] == -2) {
        cout("NO")
    } else {
        cout("YES")
        var ans = IntArray(n)
        var id = 0
        if (pre_inc[n] == -1) {
            id = 1
        }
        for (i in n downTo 1) {
            ans[i - 1] = id xor 1
            if (id == 0) {
                id = pre_inc[i]
            } else {
                id = pre_dec[i]
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