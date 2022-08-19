private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var tt = readInt()
    while (tt-- > 0) {
        var n = readInt()
        var initC = readInts()
        var c = initC.toMutableList()
        var d = readInts()
        var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })
        for (i in 0..n-2) {
            var (x, y) = readInts()
            x--
            y--
            g[x].add(y)
            g[y].add(x)
        }
        var pv = IntArray(n, {-1})
        var dist = IntArray(n, {-1})
        var start = -1
        fun Dfs(v: Int) {
            if (c[v] != d[v]) {
                if (start == -1 || dist[v] > dist[start]) {
                    start = v
                }
            }
            for (u in g[v]) {
                if (u == pv[v]) {
                    continue
                }
                pv[u] = v
                dist[u] = dist[v] + 1
                Dfs(u)
            }
        }
        dist[0] = 0
        Dfs(0)
        if (start == -1) {
            println("Yes")
            println("0")
            continue
        }
        var found = false
        for (iter in 0..1) {
            var noteq = 0
            for (i in 0..n - 1) {
                noteq += if (c[i] != d[i]) 1 else 0
            }
            pv = IntArray(n, { -1 })
            dist = IntArray(n, { -1 })
            var ans = -1
            var newstart = -1
            fun Solve(v: Int) {
                if (initC[v] != d[v]) {
                    if (newstart == -1 || dist[v] > dist[newstart]) {
                        newstart = v
                    }
                }
                if (noteq == 0) {
                    if (ans == -1 || dist[v] < dist[ans]) {
                        ans = v
                    }
                    return
                }
                for (u in g[v]) {
                    if (u == pv[v]) {
                        continue
                    }
                    var oldnoteq = noteq
                    if (c[v] != d[v]) noteq--
                    if (c[u] != d[u]) noteq--
                    var tmp = c[v]
                    c[v] = c[u]
                    c[u] = tmp
                    if (c[v] != d[v]) noteq++
                    if (c[u] != d[u]) noteq++
                    pv[u] = v
                    dist[u] = dist[v] + 1
                    Solve(u)
                    noteq = oldnoteq
                    tmp = c[v]
                    c[v] = c[u]
                    c[u] = tmp
                }
            }
            Solve(start)
            if (ans != -1) {
                println("Yes")
                var res = ArrayList<Int>()
                while (ans != start) {
                    res.add(ans + 1)
                    ans = pv[ans]
                }
                res.add(start + 1)
                res.reverse()
                println(res.size)
                println(res.joinToString(" "))
                found = true
                break
            }
            start = newstart
        }
        if (!found) println("No")
    }
}