import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m) = ints()
    var c = Array<ArrayList<Pair<Int, Int>>>(m + 1) { ArrayList<Pair<Int, Int>>() }
    for (i in 0..n - 1) {
        var k = int()
        var a = ints()
        var b = ints()
        for (j in 0..k - 1) {
            c[b[j]].add(Pair(i, a[j]))
        }
    }
    var seg = segtree(n + m + 10)
    seg.update(m, 0)
    for (i in m downTo 0) {
        for ((x, y) in c[i]) {
            seg.update(i + x + 1, maxOf(seg.get(i + x + 1, i + x + 2), seg.get(0, i + x + 1) + y))
        }
    }
    cout(seg.get(0, n + m + 10))
    print(output)
}

class segtree(_n: Int) {
    var n = 1
    val def = -10000000000000000L
    var node = longArrayOf()

    init {
        while (n < _n) {
            n *= 2
        }
        node = LongArray(2 * n - 1) { def }
    }

    fun f(a: Long, b: Long): Long {
        return maxOf(a, b)
    }

    fun update(_k: Int, v: Long) {
        var k = _k + n - 1
        node[k] = v
        while (k > 0) {
            k = (k - 1) / 2
            node[k] = f(node[2 * k + 1], node[2 * k + 2])
        }
    }

    fun get(a: Int, b: Int, k: Int = 0, l: Int = 0, r: Int = n): Long {
        if (r <= a || b <= l) return def
        if (a <= l && r <= b) return node[k]
        val vl = get(a, b, 2 * k + 1, l, (l + r) / 2)
        val vr = get(a, b, 2 * k + 2, (l + r) / 2, r)
        return f(vl, vr)
    }
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