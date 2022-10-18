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
        var (n, m) = readints()
        var a = readlongs()
        var x = readlongs()
        var ans = LongArray(m)
        var b = LongArray(n)
        for (i in 0..n - 1) {
            b[i] = a[i]
            if (i != 0) {
                b[i] += b[i - 1]
            }
        }
        var s = b[n - 1]
        for (i in 1..n - 1) {
            b[i] = max(b[i], b[i - 1])
        }
        if (s <= 0) {
            for (i in 0..m - 1) {
                if (b[n - 1] < x[i]) {
                    ans[i] = -1L
                    continue
                }
                var hi = n - 1
                var lo = -1
                while (hi - lo > 1) {
                    var mid = (hi + lo) / 2
                    if (b[mid] < x[i]) {
                        lo = mid
                    } else {
                        hi = mid
                    }
                }
                ans[i] = hi.toLong()
            }
        } else {
            for (i in 0..m - 1) {
                var k = (x[i] - b[n - 1] + s - 1) / s
                k = max(k, 0L)
                var hi = n - 1
                var lo = -1
                while (hi - lo > 1) {
                    var mid = (hi + lo) / 2
                    if (b[mid] + k * s < x[i]) {
                        lo = mid
                    } else {
                        hi = mid
                    }
                }
                ans[i] = hi.toLong() + k * n
            }
        }
        cout(ans.joinToString(" "))
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