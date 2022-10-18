import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n1, n2, m) = ints()
    var k = ints()
    var uf = dsu(n1 + n2)
    for (i in 0..n1 - 1) {
        uf.v[i] = k[i]
    }
    for (i in 0..m - 1) {
        var (x, y) = ints()
        x--
        y--
        if (!uf.unite(x, y + n1)) {
            uf.v[uf.get(x)] = 0
        }
    }
    var ans = 0L
    for (i in 0..n1 + n2 - 1) {
        if (uf.get(i) == i) {
            ans += uf.v[i]
        }
    }
    cout(ans)
    print(output)
}

class dsu(n: Int) {
    var p = IntArray(n) { it }
    var sz = IntArray(n) { 1 }
    var v = IntArray(n) { Int.MAX_VALUE }

    fun get(x: Int): Int {
        if (p[x] != x) {
            p[x] = get(p[x])
        }
        return p[x]
    }

    fun unite(_x: Int, _y: Int): Boolean {
        var x = get(_x)
        var y = get(_y)
        if (x == y) {
            return false
        }
        p[y] = x
        sz[x] += sz[y]
        v[x] = minOf(v[x], v[y])
        return true
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