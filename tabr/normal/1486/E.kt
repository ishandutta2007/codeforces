import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.AssertionError
import kotlin.math.*

val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()

fun main() {
    var (n, m) = ints()
    var g = Array(n) { ArrayList<Pair<Int, Int>>() }
    for (i in 0..m - 1) {
        var (u, v, w) = ints()
        u--
        v--
        g[u].add(Pair(v, w))
        g[v].add(Pair(u, w))
    }
    val pq = PriorityQueue<Pair<Int, Long>>(compareBy({ it.second }, { it.first }))
    pq.add(Pair(0, 0L))
    val d = LongArray(n * 51) { 1e18.toLong() }
    d[0] = 0L
    while (!pq.isEmpty()) {
        val (v, c) = pq.peek()
        pq.poll()
        if (d[v] != c) {
            continue
        }
        if (v < n) {
            for ((to, w) in g[v]) {
                if (d[to + w * n] > d[v] + w * w) {
                    d[to + w * n] = d[v] + w * w
                    pq.add(Pair(to + w * n, d[to + w * n]))
                }
            }
        } else {
            for ((to, w) in g[v % n]) {
                if (d[to] > d[v] + w * w + 2 * w * (v / n)) {
                    d[to] = d[v] + w * w + 2 * w * (v / n)
                    pq.add(Pair(to, d[to]))
                }
            }
        }
    }
    val ans = LongArray(n)
    for (i in 0..n - 1) {
        ans[i] = d[i]
        if (d[i] > 1e17.toLong()) {
            ans[i] = -1L
        }
    }
    cout(ans)
    print(output)
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