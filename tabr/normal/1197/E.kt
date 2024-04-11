import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var n = int()
    var to = IntArray(n)
    var from = IntArray(n)
    var a = IntArray(2 * n)
    for (i in 0..n - 1) {
        var (x, y) = ints()
        to[i] = x
        from[i] = y
        a[i] = x
        a[i + n] = y
    }
    var b = from.maxOrNull()!!
    a = a.toSortedSet().toIntArray()
    n = a.size
    var g = Array<ArrayList<Int>>(n) { arrayListOf() }
    for (i in 0..to.size - 1) {
        to[i] = a.binarySearch(to[i])
        from[i] = a.binarySearch(from[i])
        g[from[i]].add(to[i])
    }
    var inf = 1e9.toInt()
    var dp = Array<Pair<Int, Int>>(n) { Pair(inf, 0) }
    var ans = Pair(inf, 0)
    var mod = 1e9.toInt() + 7
    fun eval(x: Pair<Int, Int>, y: Pair<Int, Int>): Pair<Int, Int> {
        if (y.first < x.first) {
            return y
        } else if (y.first == x.first) {
            return Pair(x.first, (x.second + y.second) % mod)
        } else {
            return x
        }
    }
    dp[0] = Pair(a[0], 1)
    for (i in 0..n - 1) {
        for (j in g[i]) {
            dp[j] = eval(dp[j], dp[i])
        }
        if (i != n - 1) {
            dp[i + 1] = eval(dp[i + 1], Pair(dp[i].first + a[i + 1] - a[i], dp[i].second))
        }
        if (a[i] > b) {
            ans = eval(ans, dp[i])
        }
    }
    cout(ans.second)
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