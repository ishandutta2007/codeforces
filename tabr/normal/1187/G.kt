import java.io.*
import java.util.*
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m, k, c, d) = ints()
    var a = ints()
    var x = IntArray(m)
    var y = IntArray(m)
    for (i in 0..m - 1) {
        var (xx, yy) = ints()
        xx--
        yy--
        x[i] = xx
        y[i] = yy
    }
    var b = 103
    var z = b * n
    var fg = mcmf(z + 2, z, z + 1)
    for (i in 0..k - 1) {
        fg.add(z, a[i] - 1, 1)
    }
    for (i in 0..b - 2) {
        fg.add(i * n, z + 1, 1000)
        for (j in 1..n - 1) {
            fg.add(i * n + j, (i + 1) * n + j, 1000, 0, 1L * c)
        }
        for (j in 0..m - 1) {
            for (l in 0..21) {
                fg.add(i * n + x[j], (i + 1) * n + y[j], 1, 0, 1L * c + d * (2 * l + 1))
                fg.add(i * n + y[j], (i + 1) * n + x[j], 1, 0, 1L * c + d * (2 * l + 1))
            }
        }
    }
    cout(fg.max_flow_min_cost().second)
    print(output)
}

class edge(var from: Int, var to: Int, var c: Long, var f: Long, var cost: Long) {}

class mcmf(_n: Int, _st: Int, _fin: Int) {
    var g: Array<ArrayList<Int>>
    var edges: ArrayList<edge>
    var d: LongArray
    var q: ArrayList<Int>
    var in_queue: BooleanArray
    var pe: IntArray
    var n: Int
    var st: Int
    var fin: Int
    var flow: Long
    var cost: Long

    init {
        n = _n
        st = _st
        fin = _fin
        flow = 0
        cost = 0
        g = Array<ArrayList<Int>>(n) { arrayListOf() }
        edges = ArrayList<edge>()
        d = LongArray(n)
        q = ArrayList<Int>()
        in_queue = BooleanArray(n)
        pe = IntArray(n)
    }

    fun add(from: Int, to: Int, forward_cap: Long, backward_cap: Long = 0, _cost: Long = 0): Int {
        var id = edges.size
        g[from].add(edges.size)
        edges.add(edge(from, to, forward_cap, 0, _cost))
        g[to].add(edges.size)
        edges.add(edge(to, from, backward_cap, 0, -_cost))
        return id
    }

    fun bfs(): Boolean {
        d = LongArray(n) { Long.MAX_VALUE }
        q.clear()
        q.add(st)
        d[st] = 0
        in_queue[st] = true
        var beg = 0
        var found = false
        while (beg < q.size) {
            var i = q[beg]
            beg++
            if (i == fin) {
                found = true
            }
            in_queue[i] = false;
            for (id in g[i]) {
                var e = edges[id]
                if (e.c - e.f > 0L && d[i] + e.cost < d[e.to]) {
                    d[e.to] = d[i] + e.cost
                    pe[e.to] = id
                    if (!in_queue[e.to]) {
                        q.add(e.to)
                        in_queue[e.to] = true
                    }
                }
            }
        }
        if (found) {
            var push = Long.MAX_VALUE
            var v = fin
            while (v != st) {
                var e = edges[pe[v]]
                push = minOf(push, e.c - e.f)
                v = e.from
            }
            v = fin
            while (v != st) {
                var e = edges[pe[v]]
                e.f += push
                var back = edges[pe[v] xor 1]
                back.f -= push
                v = e.from
            }
            flow += push
            cost += push * d[fin]
        }
        return found
    }

    fun max_flow_min_cost(): Pair<Long, Long> {
        while (bfs()) continue
        return Pair(flow, cost)
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