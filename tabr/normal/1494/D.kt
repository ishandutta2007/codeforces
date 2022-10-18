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
    var a = Array<Array<Int>>(n) { Array<Int>(n) { 0 } }
    var m = 5050
    var c = ArrayList<Pair<Int, Pair<Int, Int>>>()
    for (i in 0..n - 1) {
        var b = ints()
        for (j in 0..n - 1) {
            a[i][j] = b[j]
        }
        for (j in i + 1..n - 1) {
            c.add(Pair(b[j], Pair(i, j)))
        }
    }
    c.sortWith(compareBy({ it.first }, { it.second.first }, { it.second.second }))
    var d = ArrayList<Int>()
    var uf = dsu(m)
    for (i in 0..n - 1) {
        d.add(a[i][i])
    }
    var ans = ArrayList<Pair<Int, Int>>()
    for ((x, e) in c) {
        var (u, v) = e
        u = uf.get(u)
        v = uf.get(v)
        if (u == v) {
            continue
        } else if (d[u] != x && d[v] != x) {
            ans.add(Pair(u, d.size))
            ans.add(Pair(v, d.size))
            uf.unite(u, d.size)
            uf.unite(v, d.size)
            d.add(x)
        } else if (d[u] != x) {
            ans.add(Pair(u, v))
            uf.unite(u, v)
        } else if (d[v] != x) {
            ans.add(Pair(v, u))
            uf.unite(v, u)
        }
    }
    cout(d.size)
    cout(d)
    cout(d.size)
    for (i in ans) {
        output.append(i.first + 1).append(" ").appendLine(i.second + 1)
    }
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
        p[x] = y
        sz[y] += sz[x]
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