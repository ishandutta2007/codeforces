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

const val md = 998244353

fun add(a: Int, b: Int) = (a + b) % md
fun mul(a: Int, b: Int) = ((a.toLong() * b) % md).toInt()

var dp = Array(0) { Array(4) { IntArray(4) } }

var a = IntArray(0)

fun pull(x: Int, y: Int) {
    //println("pull " + x.toString() + " " + y.toString() + " " + a[y].toString())
    for (i in 0 until 4) {
        for (j in 0 until 4) {
            dp[x][i][j] = 0
            for (u in 0 until 4) {
                for (v in 0 until 4) {
                    if (a[y] == 1) {
                        if (u > v || (u == v && (y == a.size - 1 || a[y + 1] == 0))) {
                            continue
                        }
                    } else {
                        if (u < v || (u == v && y < a.size - 1 && a[y + 1] == 1)) {
                            continue
                        }
                    }
                    dp[x][i][j] = add(dp[x][i][j], mul(dp[x + x][i][u], dp[x + x + 1][v][j]))
                }
            }
        }
    }
}

fun build(x: Int, l: Int, r: Int) {
    if (l == r) {
        for (i in 0 until 4) {
            dp[x][i][i] = 1
        }
    } else {
        val y = (l + r) shr 1
        build(x + x, l, y)
        build(x + x + 1, y + 1, r)
        pull(x, y)
    }
}

fun modify(x: Int, l: Int, r: Int, p: Int) {
    if (l < r) {
        val y = (l + r) shr 1
        if (p <= y) {
            modify(x + x, l, y, p)
        }
        if (p >= y + 1) {
            modify(x + x + 1, y + 1, r, p)
        }
        pull(x, y)
    }
}

fun main(args: Array<String>) {
    var (n, q) = readInts()
    a = readInts().toIntArray()
    dp = Array(4 * n + 10) { Array(4) { IntArray(4) } }
    build(1, 0, n - 1)
    for (u in 0 until 4) {
        for (v in 0 until 4) {
            //println(u.toString() + " " + v.toString() + " " + dp[1][u][v].toString())
        }
    }
    var ans = IntArray(q)
    for (i in 0 until q) {
        var p = readInt() - 1
        a[p] = 1 - a[p]
        modify(1, 0, n - 1, p)
        ans[i] = 0
        for (u in 0 until 4) {
            for (v in 0 until 4) {
                //println(i.toString() + ": " + u.toString() + " " + v.toString() + " " + dp[1][u][v].toString())
                ans[i] = add(ans[i], dp[1][u][v])
            }
        }
    }
    println(ans.joinToString("\n"))
}