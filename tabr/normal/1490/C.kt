import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = readint()
    var a = LongArray(10001)
    var st = TreeSet<Long>()
    for (i in 1..10000) {
        var j = i.toLong()
        a[i] = j * j * j
        st.add(j * j * j)
    }
    while (tt-- > 0) {
        var x = readlong()
        var ans = "NO"
        for (i in 1..10000) {
            if (st.contains(x - a[i])) {
                ans = "YES"
                break
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