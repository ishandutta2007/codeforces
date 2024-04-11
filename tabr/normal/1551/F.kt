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
        var d = Array<IntArray>(n) { IntArray(n) { n + 1 } }
        var g = Array<ArrayList<Int>>(n) { ArrayList<Int>() }
        for (i in 0..n - 2) {
            var (x, y) = ints()
            x--
            y--
            d[x][y] = 1
            d[y][x] = 1
            g[x].add(y)
            g[y].add(x)
        }
        for (i in 0..n - 1) {
            d[i][i] = 0
        }
        for (l in 0..n - 1) {
            for (i in 0..n - 1) {
                for (j in 0..n - 1) {
                    d[i][j] = minOf(d[i][j], d[i][l] + d[l][j])
                }
            }
        }
        var ans = 0
        for (i in 0..n - 1) {
            var a = ArrayList<IntArray>()
            if (k == 2) {
                for (j in i + 1..n - 1) {
                    if (d[i][j] % 2 == 1) {
                        ans = add(ans, 1)
                    }
                }
            }
            for (j in g[i]) {
                var b = IntArray(n)
                fun dfs(v: Int, p: Int) {
                    b[d[i][v]]++
                    for (to in g[v]) {
                        if (to == p) {
                            continue
                        }
                        dfs(to, v)
                    }
                }
                dfs(j, i)
                a.add(b)
            }
            for (j in 1..n - 1) {
                var dp = IntArray(k + 1)
                dp[0] = 1
                for (l in 0..a.size - 1) {
                    for (m in k - 1 downTo 0) {
                        dp[m + 1] = add(dp[m + 1], mul(a[l][j], dp[m]))
                    }
                }
                ans = add(ans, dp[k])
            }
        }
        cout(ans)
    }
    print(output)
}

val mod = 1e9.toInt() + 7

fun add(a: Int, b: Int): Int {
    return (a + b) % mod
}

fun sub(a: Int, b: Int): Int {
    return ((a - b) % mod + mod) % mod
}

fun mul(a: Int, b: Int): Int {
    return (a.toLong() * b % mod).toInt()
}

fun pow(_a: Int, _b: Int): Int {
    var a = _a
    var b = _b
    var res = 1
    while (b > 0) {
        if ((b and 1) != 0) {
            res = mul(res, a)
        }
        a = mul(a, a)
        b /= 2
    }
    return res
}

fun inv(_a: Int): Int {
    var a = _a
    var b = mod
    var u = 0
    var v = 1
    while (a > 0) {
        var t = b / a
        b -= t * a
        a = b.also { b = a }
        u -= t * v
        u = v.also { v = u }
    }
    if (u < 0) {
        u += mod
    }
    return u
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