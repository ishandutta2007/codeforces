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
    var t = readInt()
    for (qq in 0 until t) {
        var (h, w) = readInts()
        var a = Array(h) {IntArray(w)}
        for (i in 0 until h) {
            a[i] = readInts().toIntArray()
        }
        var cc = 0
        var b = Array(0) {IntArray(0)}
        var seq = ArrayList<Int>()
        fun dfs(i: Int, j: Int) {
            var v = a[i][j]
            a[i][j] = 0
            seq.add(v)
            for (di in -1..1) {
                for (dj in -1..1) {
                    if (di * di + dj * dj == 1) {
                        var ni = i + di
                        var nj = j + dj
                        if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
                            if (a[ni][nj] > 0) {
                                dfs(ni, nj)
                                seq.add(v)
                            }
                        }
                    }
                }
            }
        }
        for (i in 0 until h) {
            for (j in 0 until w) {
                if (a[i][j] > 0) {
                    cc += 1
                    if (cc > 1) {
                        continue
                    }
                    dfs(i, j)
                }
            }
        }
        if (cc > 1) {
            println(-1)
        } else {
            println("${seq.size / 2 + 1} ${seq.size / 2 + 1}")
            for (i in 0 until seq.size / 2 + 1) {
                println(seq.subList(i, i + seq.size / 2 + 1).joinToString(" "))
            }
        }
    }
}