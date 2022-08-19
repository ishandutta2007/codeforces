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

fun main(args: Array<String>) {
    var (n, m, k) = readInts()
    var a = readLongs()
    var b = readLongs()
    var c = Array(n) {LongArray(m) {0}}
    for (i in 0 until n) {
        var foo = readLongs()
        for (j in 0 until m) {
            c[i][j] = foo[j]
        }
    }
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (i > 0) {
                c[i][j] = maxOf(c[i][j], c[i - 1][j])
            }
            if (j > 0) {
                c[i][j] = maxOf(c[i][j], c[i][j - 1])
            }
        }
    }
    var ans = 1e18.toLong()
    fun solve(xx: Int, yy: Int, pts: Long, steps: Long, bonus: Long) {
        var x = xx
        var y = yy
        while (x + 1 < n && a[x + 1] <= pts) {
            x += 1
        }
        while (y + 1 < m && b[y + 1] <= pts) {
            y += 1
        }
        if (x == n - 1 && y == m - 1) {
            ans = minOf(ans, steps)
            return
        }
        var each = maxOf(c[x][y], bonus)
        var need = 1e18.toLong()
        if (x + 1 < n) {
            need = minOf(need, (a[x + 1] - pts + each - 1) / each)
        }
        if (y + 1 < m) {
            need = minOf(need, (b[y + 1] - pts + each - 1) / each)
        }
        solve(x, y, pts + each * need, steps + need, bonus)
        if (bonus == -1L) {
            var each = c[x][y] + k
            var need = 1e18.toLong()
            if (x + 1 < n) {
                need = minOf(need, (a[x + 1] - pts + each - 1) / each)
            }
            if (y + 1 < m) {
                need = minOf(need, (b[y + 1] - pts + each - 1) / each)
            }
            solve(x, y, pts + each * need, steps + need, each)
        }
    }
    solve(0, 0, 0L, 0L, -1L)
    println(ans)
}