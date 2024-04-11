private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- > 0) {
        var (n, k) = readInts()
        var g = Array(n, { ArrayList<Pair<Int, Int>>() })
        for (i in 0..n - 2) {
            var (x, y) = readInts()
            x--
            y--
            g[x].add(Pair(y, i))
            g[y].add(Pair(x, i))
        }
        var deg = IntArray(n)
        var cnt = 0
        for (i in 0..n-1) {
            deg[i] = g[i].size
            if (deg[i] == 1) {
                cnt += 1
            }
        }
        if (cnt < k) {
            println("No")
            continue
        }
        if (k == 1) {
            println("Yes")
            println(1)
            println(1)
            continue
        }
        var que = ArrayList<Int>()
        for (i in 0..n-1) {
            if (deg[i] == 1) {
                que.add(i)
            }
        }
        var stay = IntArray(n) {1}
        var qIt = 0
        while (qIt < que.size && cnt > k) {
            stay[que[qIt]] = 0
            for (p in g[que[qIt]]) {
                var u = p.first
                --deg[u]
                if (deg[u] == 1) {
                    que.add(u)
                } else {
                    if (deg[u] > 1) {
                        --cnt
                    }
                }
            }
            qIt++
        }
        println("Yes")
        var take = ArrayList<Int>()
        for (i in 0 until n) {
            if (stay[i] == 1) {
                take.add(i + 1)
            }
        }
        println(take.size)
        println(take.joinToString(" "))
    }
}