import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var (n, k) = readints()
        if (n % 2 == 0) {
            cout((k - 1) % n + 1)
        } else {
            var t = (k - 1) % (n / 2) + 1
            var s = ((n - (k - 1)) % n + n) % n
            s += 2 * t - 1
            cout((s - 1) % n + 1)
        }
    }
    println(output)
}

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendln(s)
fun cout(s: Int) = output.appendln(s.toString())
fun cout(s: Long) = output.appendln(s.toString())
fun assert(x: Boolean) {
    if (!x) throw AssertionError()
}