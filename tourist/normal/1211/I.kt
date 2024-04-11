private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, m) = readInts()
    var a = Array(n, {IntArray(n)})
    for (i in 0..m-1) {
        var (x, y) = readInts()
        x--
        y--
        a[x][y] = 1
        a[y][x] = 1
    }
    var g = IntArray(n)
    var cnt = 0
    for (i in 0..n-1) {
        g[i] = -1
        for (j in 0..i-1) {
            var eq = true
            for (k in 0..n-1) {
                if (a[i][k] != a[j][k]) {
                    eq = false
                    break
                }
            }
            if (eq) {
                g[i] = g[j]
                break
            }
        }
        if (g[i] == -1) {
            g[i] = cnt
            cnt++
        }
    }
    assert(cnt <= 16)
    var b = Array(cnt, {IntArray(cnt)})
    for (i in 0..n-1) {
        for (j in 0..n-1) {
            if (a[i][j] == 1) {
                b[g[i]][g[j]] = 1
            }
        }
    }
    var used = BooleanArray(16)
    var color = IntArray(cnt)
    var found = false
    fun Dfs(v: Int) {
        if (found) return
        if (v == cnt) {
            var res = IntArray(n)
            for (i in 0..n-1) {
                res[i] = color[g[i]]
            }
            println(res.joinToString(" "))
            found = true
            return
        }
        for (i in 0..15) {
            if (used[i]) {
                continue
            }
            var viable = true
            for (j in 0..v-1) {
                var XOR = i xor color[j]
                var expected = b[j][v]
                var actual = if (XOR == 1 || XOR == 2 || XOR == 4 || XOR == 8) 1 else 0
                if (expected != actual) {
                    viable = false
                    break
                }
            }
            if (viable) {
                color[v] = i
                used[i] = true
                Dfs(v + 1)
                used[i] = false
                color[v] = -1
            }
        }
    }
    Dfs(0)
    assert(found)
}