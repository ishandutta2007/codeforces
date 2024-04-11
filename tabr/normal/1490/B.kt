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
        var c = IntArray(3)
        for (i in 0..n - 1) {
            c[a[i] % 3]++
        }
        var ans = 100000000
        for (i in 0..2) {
            if (c[(i + 2) % 3] > n / 3 || c[i] < n / 3) {
                continue
            }
            ans = min(ans, c[i] - c[(i + 2) % 3])
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