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
        var (n, m) = ints()
        var u = IntArray(m)
        var v = IntArray(m)
        var w = IntArray(m)
        for (i in 0..m - 1) {
            var (x, y, z) = ints()
            x--
            y--
            u[i] = x
            v[i] = y
            w[i] = z
        }
        var ans = 0
        var dead = BooleanArray(m)
        for (x in 29 downTo 0) {
            var uf = dsu(n)
            for (i in 0..m - 1) {
                if (!dead[i] && (w[i] and (1 shl x)) == 0) {
                    uf.unite(u[i], v[i])
                }
            }
            if (uf.sz[uf.get(0)] == n) {
                for (i in 0..m - 1) {
                    if ((w[i] and (1 shl x)) != 0) {
                        dead[i] = true
                    }
                }
            } else {
                ans = ans or (1 shl x)
            }
        }
        cout(ans)
    }
    print(output)
}

class dsu(n: Int) {
    var p = IntArray(n) { it }
    var sz = IntArray(n) { 1 }

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