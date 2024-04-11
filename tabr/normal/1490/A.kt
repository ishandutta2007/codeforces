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
        var n = readint()
        var a = readints()
        var ans = 0
        for (i in 0..n - 2) {
            var b = (max(a[i], a[i + 1]) + min(a[i], a[i + 1]) - 1) / min(a[i], a[i + 1])
            var c = 2
            while (b > c) {
                ans++
                c *= 2
            }
        }
        cout(ans)
    }
    println(output)
}

fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendLine(s)
fun cout(s: Int) = output.appendLine(s.toString())
fun cout(s: Long) = output.appendLine(s.toString())
fun assert(x: Boolean) {
    if (!x) throw AssertionError()
}