import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var x = string()
    var y = string()
    var n = x.length
    var m = y.length
    val dp = Array<Array<IntArray>>(n + 1) { Array<IntArray>(m + 1) { IntArray(5) } }
    var ans = 0
    for (i in 0..n) {
        for (j in 0..m) {
            dp[i][j][0] = 1
            for (k in 0..4) {
                if (k > 2) {
                    ans = add(ans, dp[i][j][k])
                }
                if (i != n) {
                    if (k == 0 || (k % 2 == 1 && i != 0 && x[i] != x[i - 1]) || (k % 2 == 0 && j != 0 && x[i] != y[j - 1])) {
                        var l = 3
                        if (k == 0 || k == 1) {
                            l = 1
                        }
                        dp[i + 1][j][l] = add(dp[i + 1][j][l], dp[i][j][k])
                    }
                }
                if (j != m) {
                    if (k == 0 || (k % 2 == 1 && i != 0 && y[j] != x[i - 1]) || (k % 2 == 0 && j != 0 && y[j] != y[j - 1])) {
                        var l = 4
                        if (k == 0 || k == 2) {
                            l = 2
                        }
                        dp[i][j + 1][l] = add(dp[i][j + 1][l], dp[i][j][k])
                    }
                }
            }
        }
    }
    cout(ans)
    print(output)
}

val mod = 998244353

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