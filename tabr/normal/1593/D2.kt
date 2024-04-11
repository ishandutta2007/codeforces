import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        var n = int()
        var a = ints()
        a.sort()
        var ans = 0
        for (i in 0..a.size - 1) {
            a[i] += 1e6.toInt()
        }
        var m = 2e6.toInt() + 10
        var b = IntArray(m)
        for (i in a) {
            b[i]++
        }
        for (i in a) {
            if (b[i] >= n / 2) {
                ans = -1
            }
        }
        if (ans == -1) {
            cout(ans)
            continue
        }
        for (i in a) {
            b[i]--
        }
        for (i in 0..a.size - 1) {
            for (j in i + 1..a.size - 1) {
                var c = a[j] - a[i]
                var k = 1
                while (k * k <= c) {
                    if (c % k == 0) {
                        b[c / k] = 1
                        b[k] = 1
                    }
                    k++
                }
            }
        }
        var c = IntArray(m)
        for (i in 1..m - 1) {
            if (b[i] == 0) {
                continue
            }
            for (j in 0..n - 1) {
                c[a[j] % i]++
            }
            for (j in 0..n - 1) {
                if (c[a[j] % i] >= n / 2) {
                    ans = i
                }
            }
            for (j in 0..n - 1) {
                c[a[j] % i]--
            }
        }
        cout(ans)
    }
    print(output)
}

fun gcd(a: Int, b: Int): Int {
    if (b == 0) return a
    return gcd(b, a % b)
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