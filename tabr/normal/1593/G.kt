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
        var s = string()
        var n = s.length
        var a = IntArray(n)
        for (i in 0..n - 1) {
            if (s[i] == '(' || s[i] == ')') {
                a[i] = 1
            }
        }
        var seg = segtree(n)
        for (i in 0..n - 1) {
            if (a[i] == 1) {
                seg.update(i, 1)
            } else {
                seg.update(i, -1)
            }
        }
        var q = int()
        while (q-- > 0) {
            var (l, r) = ints()
            cout(abs(seg.get(l - 1, r)) / 2)
        }
    }
    print(output)
}

class segtree(_n: Int) {
    var n = 1
    val def = 0
    var node = intArrayOf()

    init {
        while (n < _n) {
            n *= 2
        }
        node = IntArray(2 * n - 1) { def }
    }

    fun f(a: Int, b: Int): Int {
        if (abs(a) % 2 == 0) {
            return a + b
        } else {
            return a - b
        }
    }

    fun update(_k: Int, v: Int) {
        var k = _k + n - 1
        node[k] = v
        while (k > 0) {
            k = (k - 1) / 2
            node[k] = f(node[2 * k + 1], node[2 * k + 2])
        }
    }

    fun get(a: Int, b: Int, k: Int = 0, l: Int = 0, r: Int = n): Int {
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