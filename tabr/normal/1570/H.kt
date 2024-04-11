import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m) = ints()
    var s = Array<String>(n) { "" }
    var st = mutableListOf<String>()
    st.add("")
    for (i in 0..n - 1) {
        var t = string()
        s[i] = t
        while (t.length > 0) {
            st.add(t)
            t = t.removeRange(0, 1)
        }
    }
    st = st.toSet().toMutableList()
    st.sort()
    var k = st.size * 4 + 1
    var a = Array<IntArray>(k) { IntArray(k) }
    for (i in 0..n - 1) {
        for (j in i..n - 1) {
            var l = minOf(s[i].length, s[j].length)
            if (s[i].substring(0, l) != s[j].substring(0, l)) {
                continue
            }
            var z = s[i]
            if (s[i].length == l) {
                z = s[j]
            }
            z = z.removeRange(0, l)
            var y = st.binarySearch(z)
            var v = 1
            if (s[i] != s[j]) {
                v++
            }
            a[(l - 1) * st.size + y][0] += v
        }
    }
    for (i in 1..st.size - 1) {
        for (j in 0..n - 1) {
            var l = minOf(st[i].length, s[j].length)
            if (st[i].substring(0, l) != s[j].substring(0, l)) {
                continue
            }
            var z = st[i]
            if (st[i].length == l) {
                z = s[j]
            }
            z = z.removeRange(0, l)
            var y = st.binarySearch(z)
            a[(l - 1) * st.size + y][i]++
        }
    }
    var c = Array<IntArray>(k) { IntArray(k) }
    for (i in 0..k - 1) {
        c[i][i] = 1
    }
    for (i in 0..a.size - st.size - 1) {
        a[i][i + st.size]++
    }
    while (m > 0) {
        if ((m and 1) == 1) {
            var b = Array<IntArray>(k) { IntArray(k) }
            for (i in 0..k - 1) {
                for (j in 0..k - 1) {
                    for (l in 0..k - 1) {
                        b[i][j] = ((b[i][j] + 1L * c[i][l] * a[l][j]) % 998244353).toInt()
                    }
                }
            }
            c = b
        }
        var b = Array<IntArray>(k) { IntArray(k) }
        for (i in 0..k - 1) {
            for (j in 0..k - 1) {
                for (l in 0..k - 1) {
                    b[i][j] = ((b[i][j] + 1L * a[i][l] * a[l][j]) % 998244353).toInt()
                }
            }
        }
        a = b
        m /= 2
    }
    cout(c[0][0])
    print(output)
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