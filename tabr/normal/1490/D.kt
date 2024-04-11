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
        var d = IntArray(n)
        var b = IntArray(n)
        for (i in 0..n - 1) {
            a[i]--
            b[a[i]] = i
        }
        for (i in n - 2 downTo 0) {
            var p = i
            var m = n
            for (j in b[i] + 1..n - 1) {
                if (a[j] > i) {
                    p = j
                    m = a[j]
                    break
                }
            }
            for (j in b[i] - 1 downTo 0) {
                if (a[j] > i) {
                    if (m > a[j]) {
                        p = j
                    }
                    break
                }
            }
            d[b[i]] = d[p] + 1
        }
        cout(d.joinToString(" "))
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