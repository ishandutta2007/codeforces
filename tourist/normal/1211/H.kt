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
        var g = Array(n, { ArrayList<Pair<Int, Int>>() })
        for (i in 0..n - 2) {
            var (x, y) = readInts()
            x--
            y--
            g[x].add(Pair(y, i))
            g[y].add(Pair(x, i))
        }
        var low = 1
        var high = n - 1
        while (low < high) {
            var mid = (low + high) / 2
            var dp = IntArray(n)
            var ok = true
            var pe = IntArray(n, { -1 })
            var pv = IntArray(n, { -1 })
            fun Dfs(v: Int, pr: Int) {
                if (!ok) return
                var children = ArrayList<Int>()
                var sum = 0
                for (uu in g[v]) {
                    var u = uu.first
                    if (u == pr) {
                        continue
                    }
                    pv[u] = v
                    pe[u] = uu.second
                    Dfs(u, v)
                    if (!ok) return
                    children.add(dp[u])
                    sum += dp[u]
                }
                var knap = BooleanArray(sum + 1, {false})
                knap[0] = true
                for (x in children) {
                    for (i in sum-x downTo 0) {
                        if (knap[i]) {
                            knap[i + x] = true
                        }
                    }
                }
                dp[v] = -1
                for (i in sum downTo 0) {
                    if (i <= mid && knap[i]) {
                        dp[v] = sum - i
                        break
                    }
                }
                if (v != 0) {
                    dp[v] += 1
                }
                if (dp[v] > mid) {
                    ok = false
                }
            }
            Dfs(0, -1)
            if (ok) {
                high = mid
            } else {
                low = mid + 1
            }
        }
        println(low)

        var mid = low

        var dp = IntArray(n)
        var pe = IntArray(n, { -1 })
        var pv = IntArray(n, { -1 })
        var knap = BooleanArray(n + 2, {false})
        fun Dfs(v: Int, pr: Int) {
            var children = ArrayList<Int>()
            var sum = 0
            for (uu in g[v]) {
                var u = uu.first
                if (u == pr) {
                    continue
                }
                pv[u] = v
                pe[u] = uu.second
                Dfs(u, v)
                children.add(dp[u])
                sum += dp[u]
            }
            for (i in 0..sum) knap[i] = false
            knap[0] = true
            for (x in children) {
                for (i in sum-x downTo 0) {
                    if (knap[i]) {
                        knap[i + x] = true
                    }
                }
            }
            dp[v] = -1
            for (i in sum downTo 0) {
                if (i <= mid && knap[i]) {
                    dp[v] = sum - i
                    break
                }
            }
            if (v != 0) {
                dp[v] += 1
            }
            assert(dp[v] <= mid)
        }
        Dfs(0, -1)

        var colors = IntArray(n - 1)
        var kdp = Array(n + 2, {BooleanArray(n + 2, {false})})
        var take = BooleanArray(n, {false})

        fun Restore(v: Int, pr: Int) {
            var children = ArrayList<Int>()
            var cv = ArrayList<Int>()
            var sum = 0
            for (uu in g[v]) {
                var u = uu.first
                if (u == pr) {
                    continue
                }
                pv[u] = v
                pe[u] = uu.second
                children.add(dp[u])
                cv.add(u)
                sum += dp[u]
            }
            var sz = children.size
            for (i in 0..sz) {
                for (j in 0..sum) {
                    kdp[i][j] = false
                }
            }
            kdp[0][0] = true
            for (xt in 0..sz - 1) {
                var x = children[xt]
                for (i in 0..sum) {
                    if (kdp[xt][i]) {
                        if (i + x <= sum) {
                            kdp[xt + 1][i + x] = true
                        }
                        kdp[xt + 1][i] = true
                    }
                }
            }
            var res = -1
            for (i in sum downTo 0) {
                if (i <= mid && kdp[sz][i]) {
                    res = i
                    break
                }
            }
            for (i in (sz-1) downTo 0) {
                if (!kdp[i][res]) {
                    res -= children[i]
                    take[cv[i]] = true
                }
            }
            for (i in 0..sz-1) {
                if (take[cv[i]]) {
                    colors[pe[cv[i]]] = v + 1
                } else {
                    colors[pe[cv[i]]] = if (v == 0) 787788 else colors[pe[v]]
                }
            }
            for (i in 0..sz-1) {
                Restore(cv[i], v)
            }
        }
        Restore(0, -1)

        println(colors.joinToString(" "))
    }
}