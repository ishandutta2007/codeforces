import java.lang.Math.abs
import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, k) = readInts()
    var g = Array(n, {ArrayList<Pair<Int, Int>>()})
    for (i in 0..n-2) {
        var (x, y) = readInts()
        x--
        y--
        g[x].add(Pair(y, i + 1))
        g[y].add(Pair(x, i + 1))
    }
    var dp = Array(n, {IntArray(0)})
    var sz = IntArray(n)
    var pe = IntArray(n, {-1})
    var pv = IntArray(n, {-1})
    fun Dfs(v: Int, pr: Int) {
        var aux = IntArray(2)
        aux[0] = n + 1
        aux[1] = 0
        sz[v] = 1
        for (uu in g[v]) {
            var u = uu.first
            if (u == pr) {
                continue
            }
            pv[u] = v
            pe[u] = uu.second
            Dfs(u, v)
            var newAux = IntArray(sz[v] + sz[u] + 1, {n + 1})
            for (x in 0..sz[v]) {
                for (y in 0..sz[u]) {
                    newAux[x + y] = min(newAux[x + y], aux[x] + dp[u][y])
                }
            }
            sz[v] += sz[u]
            aux = newAux
        }
        dp[v] = aux
        dp[v][0] = 1
    }
    Dfs(0, -1)
    var ans = n + 1
    var ver = -1
    for (i in 0..n-1) {
        if (sz[i] < k) {
            continue
        }
        var cur = dp[i][k] + (if (i == 0) 0 else 1)
        if (cur < ans) {
            ans = cur
            ver = i
        }
    }
    println(ans)
    var res = ArrayList<Int>()
    fun Restore(v: Int, pr: Int, cc: Int) {
        var children = ArrayList<Pair<Int, Int>>()
        for (uu in g[v]) {
            var u = uu.first
            if (u == pr) {
                continue
            }
            children.add(uu)
        }
        var cnt = children.size
        var inner = ArrayList<IntArray>()
        var aux = IntArray(2)
        aux[0] = n + 1
        aux[1] = 0
        sz[v] = 1
        inner.add(aux)
        for (uu in children) {
            var u = uu.first
            var newAux = IntArray(sz[v] + sz[u] + 1, {n + 1})
            for (x in 0..sz[v]) {
                for (y in 0..sz[u]) {
                    newAux[x + y] = min(newAux[x + y], aux[x] + dp[u][y])
                }
            }
            sz[v] += sz[u]
            aux = newAux
            inner.add(aux)
        }
        var ccs = IntArray(cnt)
        var ccc = cc
        for (i in cnt-1 downTo 0) {
            var u = children[i].first
            var found = false
            for (x in 0..min(ccc, inner[i].size)) {
                var y = ccc - x
                if (y <= sz[u] && inner[i][x] + dp[u][y] == inner[i + 1][ccc]) {
                    ccs[i] = y
                    ccc -= y
                    found = true
                    break
                }
            }
            assert(found)
        }
        assert(ccc == 1)
        for (i in 0..cnt-1) {
            if (ccs[i] == 0) {
                res.add(children[i].second)
            } else {
                Restore(children[i].first, v, ccs[i])
            }
        }
    }
    if (ver != 0) {
        res.add(pe[ver])
    }
    Restore(ver, pv[ver], k)
    println(res.joinToString(" "))
}