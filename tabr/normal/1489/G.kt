import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m) = ints()
    var a = longs()
    var e = ArrayList<Triple<Long, Int, Int>>()
    for (i in 0..m - 1) {
        var (x, y, z) = longs()
        x--
        y--
        e.add(Triple(z, x.toInt(), y.toInt()))
    }
    var mn1 = 1e15.toLong()
    var mn2 = 1e15.toLong()
    var id1 = -1
    var id2 = -1
    for (i in 0..n - 1) {
        if (a[i] <= mn1) {
            mn2 = mn1
            mn1 = a[i]
            id2 = id1
            id1 = i
        } else if (a[i] <= mn2) {
            mn2 = a[i]
            id2 = i
        }
    }
    for (i in 0..n - 1) {
        if (id1 == i) {
            e.add(Triple(mn2 + a[i], id2, i))
        } else {
            e.add(Triple(mn1 + a[i], id1, i))
        }
    }
    e.sortWith(compareBy({ it.first }, { it.second }, { it.third }))
    var uf = dsu(n)
    var ans = 0L
    for ((z, x, y) in e) {
        if (x == -1 || y == -1) {
            continue
        }
        if (!uf.same(x, y)) {
            ans += z
            uf.unite(x, y)
        }
    }
    cout(ans)
    print(output)
}

class dsu(n: Int) {
    var p = IntArray(n) { it }
    var sz = IntArray(n) { 1 }

    fun get(x: Int): Int {
        if (p[x] == x) {
            return x
        } else {
            p[x] = get(p[x])
            return p[x]
        }
    }

    fun unite(_x: Int, _y: Int) {
        var x = _x
        var y = _y
        x = get(x);
        y = get(y);
        if (x == y) {
            return
        }
        if (sz[x] > sz[y]) {
            p[y] = x
            sz[x] += sz[y]
        } else {
            p[x] = y
            sz[y] += sz[x]
        }
    }

    fun same(x: Int, y: Int): Boolean {
        return (get(x) == get(y))
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