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

const val intInf = (1e9).toInt()
const val longInf = (4e18).toLong()

fun main(args: Array<String>) {
    var (n, m, q, s) = readInts()
    s -= 1
    var a = readInts()
    var g = Array(n, {IntArray(n) {intInf} })
    for (i in 0 until m) {
        var (x, y) = readInts()
        g[x - 1][y - 1] = 1
    }
    var c = readLongs()
    var total = 0L
    for (x in a) {
        total += x
    }
    for (i in 0 until n) {
        g[i][i] = 0
    }
    for (k in 0 until n) {
        for (i in 0 until n) {
            for (j in 0 until n) {
                g[i][j] = minOf(g[i][j], g[i][k] + g[k][j])
            }
        }
    }
    var dp = Array(n, {Array(1 shl n, {IntArray(n) {intInf}})})
    for (start in 0 until n) {
        dp[start][1 shl start][start] = 0
        for (mask in 0 until (1 shl n)) {
            for (v in 0 until n) {
                if (dp[start][mask][v] < intInf) {
                    for (u in 0 until n) {
                        if ((mask and (1 shl u)) == 0) {
                            var ft = dp[start][mask][v] + g[v][u]
                            dp[start][mask or (1 shl u)][u] = minOf(dp[start][mask or (1 shl u)][u], ft)
                        }
                    }
                }
            }
        }
    }
    var maskSum = LongArray(1 shl n) {0}
    for (mask in 0 until (1 shl n)) {
        for (i in 0 until n) {
            if ((mask and (1 shl i)) != 0) {
                maskSum[mask] += a[i].toLong()
            }
        }
    }
    var parts = Array(n) { LongArray(n * n + 1) {0} }
    for (start in 0 until n) {
        for (mask in 0 until (1 shl n)) {
            for (v in 0 until n) {
                if (dp[start][mask][v] < intInf) {
                    parts[start][dp[start][mask][v]] = maxOf(parts[start][dp[start][mask][v]], maskSum[mask])
                }
            }
        }
    }
    var mat = Array(n) { LongArray(n) {longInf} }
    for (i in 0 until n) {
        for (j in 0 until n) {
            for (k in 0 until n) {
                mat[i][j] = minOf(mat[i][j], (dp[i][(1 shl n) - 1][k] + g[k][j]).toLong())
            }
        }
    }
    var powers = Array(60) { Array(n) { LongArray(n) } }
    for (i in 0 until n) {
        for (j in 0 until n) {
            powers[0][i][j] = mat[i][j]
        }
    }
    for (iter in 1 until 60) {
        for (i in 0 until n) {
            for (j in 0 until n) {
                powers[iter][i][j] = longInf
                for (k in 0 until n) {
                    powers[iter][i][j] = minOf(powers[iter][i][j], powers[iter - 1][i][k] + powers[iter - 1][k][j])
                }
            }
        }
    }
    var res = LongArray(q) {longInf}
    for (qq in 0 until q) {
        var dist = LongArray(n) {longInf}
        dist[s] = 0
        var auxDist = LongArray(n)
        var full = c[qq] / total
        for (iter in 0 until 60) {
            if ((full and (1L shl iter)) != 0L) {
                for (i in 0 until n) {
                    auxDist[i] = longInf
                    for (j in 0 until n) {
                        auxDist[i] = minOf(auxDist[i], dist[j] + powers[iter][j][i])
                    }
                }
                for (i in 0 until n) {
                    dist[i] = auxDist[i]
                }
            }
        }
        var rem = c[qq] % total
        for (i in 0 until n) {
            for (j in 0 until n * n + 1) {
                if (parts[i][j] >= rem) {
                    res[qq] = minOf(res[qq], dist[i] + j)
                }
            }
        }
    }
    println(res.joinToString("\n"))
}