import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var n = readint()
        var a = readints()
        a.sort()
        var beg = 0
        var end = 0
        var b = ArrayList<Int>()
        while (beg < n) {
            while (end < n && a[beg] == a[end]) {
                end++
            }
            b.add(end - beg)
            beg = end
        }
        b.sort()
        var ans = 100000000
        var pre = 0
        var suf = n
        var m = b.size
        for (i in 0..m - 1) {
            ans = min(ans, pre + suf - (m - i) * b[i])
            pre += b[i]
            suf -= b[i]
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