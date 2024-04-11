import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val adj = Array(n + 1) { mutableListOf<Edge>() }
    val rev = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        val (a, b, l) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(Edge(b, l.toLong()))
        rev[b].add(a)
    }
    val seen = BooleanArray(n + 1)
    val order = mutableListOf<Int>()
    // thanks wikipedia and kosaraju and sharir
    fun visit(a: Int) {
        if (!seen[a]) {
            //println("visiting $a")
            seen[a] = true
            for ((b) in adj[a]) {
                visit(b)
            }
            order.add(a)
            //println("bye $a")
        }
    }
    for (a in 1..n) {
        visit(a)
    }
    //println(order)
    val sccs = IntArray(n + 1)
    fun assign(a: Int) {
        for (b in rev[a]) {
            if (sccs[b] == 0) {
                sccs[b] = sccs[a]
                assign(b)
            }
        }
    }
    for (a in order.reversed()) {
        if (sccs[a] == 0) {
            sccs[a] = a
            assign(a)
        }
    }
    //println(sccs.contentToString())
    val dists = LongArray(n + 1)
    seen.fill(false)
    for (r in 1..n) {
        if (sccs[r] == r) {
            fun dfs(a: Int) {
                for ((b, l) in adj[a]) {
                    if (sccs[b] == r && !seen[b]) {
                        seen[b] = true
                        dists[b] = dists[a] + l
                        dfs(b)
                    }
                }
            }
            seen[r] = true
            dfs(r)
        }
    }
    val gs = LongArray(n + 1)
    for (a in 1..n) {
        for ((b, l) in adj[a]) {
            if (sccs[b] == sccs[a]) {
                gs[sccs[a]] = gcd(gs[sccs[a]], abs((dists[a] - dists[b]) + l))
            }
        }
    }
    val q = jin.readLine().toInt()
    val out = StringBuilder()
    for (j in 1..q) {
        val line = jin.readLine().split(" ")
        val a = line[0].toInt()
        val x = line[1].toLong()
        val y = line[2].toLong()
        val g = gcd(gs[sccs[a]], y)
        out.appendln(if (x % g == 0L) "YES" else "NO")
    }
    print(out)
}

data class Edge(val to: Int, val length: Long)

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)