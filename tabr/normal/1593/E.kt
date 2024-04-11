import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var tt = int()
    while (tt-- > 0) {
        string()
        var (n, k) = ints()
        var g = Array<ArrayList<Int>>(n) { ArrayList() }
        var deg = IntArray(n)
        for (i in 0..n - 2) {
            var (x, y) = ints()
            x--
            y--
            deg[x]++
            deg[y]++
            g[x].add(y)
            g[y].add(x)
        }
        var ans = n
        var l = ArrayList<Int>()
        for (i in 0..n - 1) {
            if (deg[i] == 1) {
                l.add(i)
            }
        }
        while (k-- > 0) {
            if (ans <= 2) {
                ans = 0
                break
            }
            var nl = ArrayList<Int>()
            for (i in l) {
                ans--
                deg[i] = 0
                for (j in g[i]) {
                    if (deg[j] > 0) {
                        deg[j]--
                        if (deg[j] == 1) {
                            nl.add(j)
                        }
                        break
                    }
                }
            }
            l = nl
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