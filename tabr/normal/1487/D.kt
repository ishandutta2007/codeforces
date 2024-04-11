import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var x = ArrayList<Int>()
    var y = ArrayList<Int>()
    for (i in 1..100000) {
        var a = 2 * i + 1
        var b = (a * a - 1) / 2
        if (b + 1 > 1000000000) {
            break
        }
        if (1L * a * a + 1L * b * b == 1L * (b + 1) * (b + 1)) {
            x.add(b + 1)
            y.add(x.size)
        }
    }
    var tt = readint()
    while (tt-- > 0) {
        var n = readint()
        if (n < 5) {
            cout(0)
            continue
        }
        var lo = 0
        var hi = x.size
        while (hi - lo > 1) {
            var mid = (hi + lo) / 2
            if (x[mid] > n) {
                hi = mid
            } else {
                lo = mid
            }
        }
        cout(hi)
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