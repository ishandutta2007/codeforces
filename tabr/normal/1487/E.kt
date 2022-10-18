import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var n = readints()
    var x = Array(4) { it -> LongArray(n[it]) }
    for (i in 0..3) {
        var a = readlongs()
        for (j in 0..n[i] - 1) {
            x[i][j] = a[j]
        }
    }
    for (i in 0..2) {
        var st = segtree(n[i])
        for (j in 0..n[i] - 1) {
            st.update(j, x[i][j])
        }
        var m = readint()
        var a = Array(n[i + 1]) { ArrayList<Int>() }
        for (j in 0..m - 1) {
            var (b, c) = readints()
            b--
            c--
            a[c].add(b)
        }
        for (j in 0..n[i + 1] - 1) {
            a[j].add(-1)
            a[j].add(n[i])
            a[j].sort()
            var s = 1000000000000L
            for (k in 0..a[j].size - 2) {
                if (a[j][k] + 1 != a[j][k + 1]) {
                    s = minOf(s, st.get(a[j][k] + 1, a[j][k + 1]))
                }
            }
            x[i + 1][j] += s
        }
    }
    var ans = x[3].min()!!
    if (ans > 10000000000L) {
        ans = -1L
    }
    cout(ans)
    println(output)
}

class segtree(_n: Int) {
    var n = 1
    val def = 1000000000000L
    var node = longArrayOf()

    init {
        while (n < _n) {
            n *= 2
        }
        node = LongArray(2 * n - 1) { def }
    }

    fun f(a: Long, b: Long): Long {
        return minOf(a, b)
    }

    fun update(_k: Int, v: Long) {
        var k = _k + n - 1
        node[k] = v
        while (k > 0) {
            k = (k - 1) / 2
            node[k] = f(node[2 * k + 1], node[2 * k + 2])
        }
    }

    fun gett(a: Int, b: Int, k: Int, l: Int, r: Int): Long {
        if (r <= a || b <= l) return def
        if (a <= l && r <= b) return node[k]
        val vl = gett(a, b, 2 * k + 1, l, (l + r) / 2)
        val vr = gett(a, b, 2 * k + 2, (l + r) / 2, r)
        return f(vl, vr)
    }

    fun get(a: Int, b: Int): Long {
        return gett(a, b, 0, 0, n)
    }
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