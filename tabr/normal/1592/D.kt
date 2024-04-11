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
    var g = Array<ArrayList<Int>>(n) { arrayListOf() }
    for (i in 0..n - 2) {
        var (x, y) = ints()
        x--
        y--
        g[x].add(y)
        g[y].add(x)
    }
    var b = IntArray(n) { it + 1 }
    println("? ${n} " + b.joinToString(" "))
    System.out.flush()
    var mx = int()
    var edges = ArrayList<Pair<Int, Int>>()
    fun dfs(v: Int, p: Int) {
        for (to in g[v]) {
            if (to == p) {
                continue
            }
            edges.add(Pair(v + 1, to + 1))
            dfs(to, v)
        }
    }
    dfs(0, -1)
    while (edges.size > 1) {
        var vs = ArrayList<Int>()
        for (i in 0..edges.size / 2 - 1) {
            vs.add(edges[i].first)
            vs.add(edges[i].second)
        }
        var vv = vs.distinct()
        println("? ${vv.size} " + vv.joinToString(" "))
        System.out.flush()
        var t = int()
        var new_edges = ArrayList<Pair<Int, Int>>()
        if (t == mx) {
            for (i in 0..edges.size / 2 - 1) {
                new_edges.add(edges[i])
            }
        } else {
            for (i in edges.size / 2..edges.size - 1) {
                new_edges.add(edges[i])
            }
        }
        edges = new_edges
    }
    println("! ${edges[0].first} ${edges[0].second}")
    System.out.flush()
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