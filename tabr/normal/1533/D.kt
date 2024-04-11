import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m) = ints()
    var s = mutableSetOf<String>()
    for (i in 0..n - 1) {
        var t = string()
        s.add(t)
    }
    var q = int()
    for (i in 0..q - 1) {
        var t = string()
        var ans = 0
        var z = mutableSetOf<String>()
        for (j in 0..m) {
            var u = ""
            for (k in 0..m) {
                if (k != j) {
                    u += t[k]
                }
            }
            z.add(u)
        }
        for (u in z) {
            if (s.contains(u)) {
                ans++
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