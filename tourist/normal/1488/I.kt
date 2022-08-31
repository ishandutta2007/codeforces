import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

class Edge(val from: Int, val to: Int, val c: Int, var f: Int) { }

fun main(args: Array<String>) {
    var (n, m, k) = readInts()
    var g = Array(n) {ArrayList<Pair<Int, Int>>()}
    for (i in 0 until m) {
        var (x, y) = readInts()
        g[x - 1].add(Pair(y - 1, i))
        g[y - 1].add(Pair(x - 1, i))
    }
    var d = IntArray(n) {-1}
    var que = ArrayList<Int>()
    d[0] = 0
    que.add(0)
    var edges = ArrayList<Edge>()
    var st = n + m
    var fin = n + m + 1
    var qIt = 0
    while (qIt < que.size) {
        var u = que[qIt++]
        for ((v, it) in g[u]) {
            if (d[v] == -1) {
                que.add(v)
                d[v] = d[u] + 1
            }
            if (d[v] == d[u] + 1) {
                if (d[u] % 2 == 0) {
                    edges.add(Edge(st, n + it, 1, 0))
                    edges.add(Edge(n + it, st, 0, 0))
                    edges.add(Edge(n + it, u, 1, 0))
                    edges.add(Edge(u, n + it, 0, 0))
                    edges.add(Edge(n + it, v, 1, 0))
                    edges.add(Edge(v, n + it, 0, 0))
                } else {
                    edges.add(Edge(u, n + it, 1, 0))
                    edges.add(Edge(n + it, u, 0, 0))
                    edges.add(Edge(v, n + it, 1, 0))
                    edges.add(Edge(n + it, v, 0, 0))
                    edges.add(Edge(n + it, fin, 1, 0))
                    edges.add(Edge(fin, n + it, 0, 0))
                }
            }
        }
    }
    var out = Array(n + m + 2) {ArrayList<Int>()}
    for (i in 0 until edges.size) {
        out[edges[i].from].add(i)
    }
    var ptr = IntArray(n + m + 2)
    var dst = IntArray(n + m + 2)
    var q = IntArray(n + m + 2)
    var ans = 0
    while (true) {
        for (i in 0 until n + m + 2) {
            dst[i] = -1
        }
        q[0] = fin
        dst[fin] = 0
        var beg = 0
        var end = 1
        var found = false
        while (beg < end) {
            var i = q[beg++]
            for (it in out[i]) {
                var e = edges[it]
                var back = edges[it xor 1]
                if (back.c > back.f && dst[e.to] == -1) {
                    dst[e.to] = dst[i] + 1
                    if (e.to == st) {
                        found = true
                        break
                    }
                    q[end++] = e.to
                }
            }
            if (found) {
                break
            }
        }
        if (!found) {
            break
        }
        for (i in 0 until n + m + 2) {
            ptr[i] = out[i].size - 1
        }
        fun dfs(v: Int, w: Int) : Int {
            if (v == fin) {
                return w
            }
            while (ptr[v] >= 0) {
                var it = out[v][ptr[v]]
                var e = edges[it]
                if (e.c > e.f && dst[e.to] == dst[v] - 1) {
                    var t = dfs(e.to, minOf(e.c - e.f, w))
                    if (t > 0) {
                        edges[it].f += t
                        edges[it xor 1].f -= t
                        return t
                    }
                }
                ptr[v] -= 1
            }
            return 0
        }
        var bigAdd = 0
        while (true) {
            var add = dfs(st, n + m + 2)
            if (add == 0) {
                break
            }
            bigAdd += add
        }
        if (bigAdd == 0) {
            break
        }
        ans += bigAdd
    }
    println(minOf(ans, k))
}