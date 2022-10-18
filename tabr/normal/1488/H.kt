import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.collections.ArrayList
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()
var mod = 998244353

fun add(a: Int, b: Int): Int {
    return (a + b) % mod
}

fun sub(a: Int, b: Int): Int {
    return ((a - b) % mod + mod) % mod
}

fun mul(a: Int, b: Int): Int {
    return (1L * a * b % mod).toInt()
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

var E = Array<IntArray>(4) { IntArray(4) }
var C0 = Array<IntArray>(4) { IntArray(4) }
var C1 = Array<IntArray>(4) { IntArray(4) }
var D0 = Array<IntArray>(4) { IntArray(4) }
var D1 = Array<IntArray>(4) { IntArray(4) }

fun main() {
    var (n, q) = ints()
    var a = ints()
    for (i in 0..3) {
        for (j in 0..i) {
            C1[i][j] = 1
        }
        for (j in 0..i - 1) {
            D1[i][j] = 1
        }
    }
    for (i in 0..3) {
        for (j in i..3) {
            C0[i][j] = 1
        }
        for (j in i + 1..3) {
            D0[i][j] = 1
        }
    }
    for (i in 0..3) {
        E[i][i] = 1
    }
    var st = segtree(n)
    a.add(0)
    for (i in 0..n - 2) {
        if (a[i] == 0) {
            if (a[i + 1] == 0) {
                st.update(i, C0)
            } else {
                st.update(i, D0)
            }
        } else {
            if (a[i + 1] == 1) {
                st.update(i, C1)
            } else {
                st.update(i, D1)
            }
        }
    }
    while (q-- > 0) {
        var i = int()
        i--
        a[i] = a[i] xor 1
        if (a[i] == 0) {
            if (a[i + 1] == 0) {
                st.update(i, C0)
            } else {
                st.update(i, D0)
            }
        } else {
            if (a[i + 1] == 1) {
                st.update(i, C1)
            } else {
                st.update(i, D1)
            }
        }
        if (i != 0) {
            if (a[i - 1] == 0) {
                if (a[i] == 0) {
                    st.update(i - 1, C0)
                } else {
                    st.update(i - 1, D0)
                }
            } else {
                if (a[i] == 1) {
                    st.update(i - 1, C1)
                } else {
                    st.update(i - 1, D1)
                }
            }
        }
        var b = st.node[0]
        var ans = 0
        for (x in 0..3) {
            for (y in 0..3) {
                ans = add(ans, b[x][y])
            }
        }
        cout(ans)
    }
    print(output)
}

class segtree(_n: Int) {
    var n = 1
    val def = E
    var node = arrayOf<Array<IntArray>>()

    init {
        while (n < _n) {
            n *= 2
        }
        node = Array(2 * n - 1) { def }
    }

    fun f(a: Array<IntArray>, b: Array<IntArray>): Array<IntArray> {
        var c = Array<IntArray>(4) { IntArray(4) }
        for (i in 0..3) {
            for (j in 0..3) {
                for (l in 0..3) {
                    c[i][j] = add(c[i][j], mul(a[i][l], b[l][j]))
                }
            }
        }
        return c
    }

    fun update(_k: Int, v: Array<IntArray>) {
        var k = _k + n - 1
        node[k] = v
        while (k > 0) {
            k = (k - 1) / 2
            node[k] = f(node[2 * k + 1], node[2 * k + 2])
        }
    }

    fun get(a: Int, b: Int, k: Int = 0, l: Int = 0, r: Int = n): Array<IntArray> {
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