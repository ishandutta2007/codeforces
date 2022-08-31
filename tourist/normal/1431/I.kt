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
    var (n, m, q) = readInts()
    var orig = Array(n + q) { CharArray(m) }
    var s = Array(m) { CharArray(n + q) }
    for (i in 0 until n + q) {
        var foo = readLn()
        for (j in 0 until m) {
            orig[i][j] = foo[j]
            s[j][i] = foo[j]
        }
    }
    var order = Array(m + 1) { IntArray(n + q) }
    for (i in 0 until n + q) {
        order[m][i] = i
    }
    var pz = Array(m) { IntArray(n + q) }
    var prev = Array(m) { IntArray(n + q) }
    var next = Array(m) { IntArray(n + q) }
    for (j in m - 1 downTo 0) {
        var pos = 0
        for (c in 'a'..'z') {
            for (i in order[j + 1]) {
                if (s[j][i] == c) {
                    order[j][pos] = i
                    pz[j][i] = pos
                    pos += 1
                }
            }
        }
        myAssert(pos == n + q)
        for (i in 0 until n + q) {
            if (order[j][i] < n) {
                prev[j][i] = order[j][i]
            } else {
                if (i == 0) {
                    prev[j][i] = 0
                } else {
                    prev[j][i] = prev[j][i - 1]
                }
            }
        }
        for (i in n + q - 1 downTo 0) {
            if (order[j][i] < n) {
                next[j][i] = order[j][i]
            } else {
                if (i == n + q - 1) {
                    next[j][i] = 0
                } else {
                    next[j][i] = next[j][i + 1]
                }
            }
        }
    }
    for (id in n until n + q) {
        var j = 0
        var ans = -1
        while (j < m) {
            var me = pz[j][id]
            var x = prev[j][me]
            var y = next[j][me]
            var cntX = 0
            while (j + cntX < m && orig[x][j + cntX] == orig[id][j + cntX]) {
                cntX += 1
            }
            var cntY = 0
            while (j + cntY < m && orig[y][j + cntY] == orig[id][j + cntY]) {
                cntY += 1
            }
            var cnt = maxOf(cntX, cntY)
            if (cnt == 0) {
                ans = -1
                break
            }
            j += cnt
            ans += 1
        }
        println(ans)
    }
}