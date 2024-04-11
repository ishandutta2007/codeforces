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
        if (n == 2) {
            cout(0)
            continue
        }
        for (i in 0..n - 1) {
            for (j in i + 1..n - 1) {
                if ((j - i) * 2 == n) {
                    output.append("0 ")
                } else if ((j - i) * 2 < n) {
                    output.append("1 ")
                } else {
                    output.append("-1 ")
                }
            }
        }
        cout("")
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