import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m, k) = ints()
    var g = Array<ArrayList<Int>>(n) { ArrayList<Int>() }
    var edges = Array<Pair<Int, Int>>(m) { Pair(0, 0) }
    for (i in 0..m - 1) {
        var (x, y) = ints()
        x--
        y--
        g[x].add(y)
        g[y].add(x)
        edges[i] = Pair(x, y)
    }
    var que = ArrayDeque<Int>()
    que.addLast(0)
    var d = IntArray(n) { -1 }
    d[0] = 0
    while (!que.isEmpty()) {
        var v = que.first()
        que.pollFirst()
        for (to in g[v]) {
            if (d[to] == -1) {
                d[to] = d[v] + 1
                que.addLast(to)
            }
        }
    }
    var fg = dinic(n + m + 2, n + m, n + m + 1)
    for (i in 0..m - 1) {
        var (x, y) = edges[i]
        if (abs(d[x] - d[y]) != 1) {
            continue
        }
        var c = minOf(d[x], d[y]) % 2
        if (c == 0) {
            fg.add(n + m, i + n, 1)
            fg.add(i + n, x, 1)
            fg.add(i + n, y, 1)
        } else {
            fg.add(i + n, n + m + 1, 1)
            fg.add(x, i + n, 1)
            fg.add(y, i + n, 1)
        }
    }
    cout(minOf(k.toInt(), fg.max_flow()))
    print(output)
}

class edge(var from: Int, var to: Int, var c: Int, var f: Int) {}

class dinic(_n: Int, _s: Int, _t: Int) {
    var g: Array<ArrayList<Int>>
    var edges: ArrayList<edge>
    var ptr: IntArray
    var d: IntArray
    var q: IntArray
    var n: Int
    var s: Int
    var t: Int
    var flow: Int

    init {
        n = _n
        s = _s
        t = _t
        flow = 0
        g = Array<ArrayList<Int>>(n) { arrayListOf() }
        edges = ArrayList<edge>()
        ptr = IntArray(n)
        d = IntArray(n)
        q = IntArray(n)
    }

    fun add(from: Int, to: Int, forward_cap: Int, backward_cap: Int = 0): Int {
        var id = edges.size
        g[from].add(id)
        edges.add(edge(from, to, forward_cap, 0))
        g[to].add(id + 1)
        edges.add(edge(to, from, backward_cap, 0))
        return id
    }

    fun bfs(): Boolean {
        for (i in 0..n - 1) {
            d[i] = -1
        }
        q[0] = t
        d[t] = 0
        var beg = 0
        var end = 1
        while (beg < end) {
            var i = q[beg++]
            for (id in g[i]) {
                var e = edges[id]
                var back = edges[id xor 1]
                if (back.c - back.f > 0 && d[e.to] == -1) {
                    d[e.to] = d[i] + 1
                    if (e.to == s) {
                        return true
                    }
                    q[end++] = e.to
                }
            }
        }
        return false
    }

    fun dfs(v: Int, w: Int): Int {
        if (v == t) {
            return w
        }
        while (ptr[v] >= 0) {
            var id = g[v][ptr[v]]
            var e = edges[id]
            if (e.c - e.f > 0 && d[e.to] == d[v] - 1) {
                var df = dfs(e.to, minOf(e.c - e.f, w))
                if (df > 0) {
                    edges[id].f += df
                    edges[id xor 1].f -= df
                    return df
                }
            }
            ptr[v]--
        }
        return 0
    }

    fun max_flow(): Int {
        while (bfs()) {
            for (i in 0..n - 1) {
                ptr[i] = g[i].size - 1
            }
            var sum = 0
            while (true) {
                var add = dfs(s, Int.MAX_VALUE)
                if (add <= 0L) {
                    break
                }
                sum += add
            }
            if (sum <= 0L) {
                break
            }
            flow += sum
        }
        return flow
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