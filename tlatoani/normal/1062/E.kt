import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val children = Array(n + 1) { mutableListOf<Int>() }
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 2..n) {
        children[tokenizer.nextToken().toInt()].add(j)
    }
    val parent = Array(17) { IntArray(n + 1) }
    val depth = IntArray(n + 1)
    fun recur(a: Int) {
        for (b in children[a]) {
            parent[0][b] = a
            for (e in 1..16) {
                parent[e][b] = parent[e - 1][parent[e - 1][b]]
            }
            depth[b] = depth[a] + 1
            recur(b)
        }
    }
    recur(1)
    fun lca(a: Int, b: Int): Int {
        var (a, b) = if (depth[a] < depth[b]) Pair(a, b) else Pair(b, a)
        for (e in 16 downTo 0) {
            if (depth[b] - depth[a] >= 1 shl e) {
                b = parent[e][b]
            }
        }
        if (a == b) {
            return a
        }
        for (e in 16 downTo 0) {
            if (parent[e][a] != parent[e][b]) {
                a = parent[e][a]
                b = parent[e][b]
            }
        }
        return parent[0][a]
    }
    val rmq = Array(17) { IntArray(n + 1) }
    for (a in 1..n) {
        rmq[0][a] = a
    }
    for (e in 1..16) {
        for (a in 1..n - (1 shl e) + 1) {
            rmq[e][a] = lca(rmq[e - 1][a], rmq[e - 1][a + (1 shl (e - 1))])
        }
    }
    fun queryRMQ(from: Int, to: Int): Int {
        var e = 0
        while (1 shl e <= to - from + 1) {
            e++
        }
        e--
        return lca(rmq[e][from], rmq[e][to - (1 shl e) + 1])
    }
    val out = StringBuilder()
    for (j in 1..q) {
        val (l, r) = jin.readLine().split(" ").map { it.toInt() }
        if (l + 1 == r) {
            if (depth[l] > depth[r]) {
                out.append(r).append(' ').appendln(depth[l])
            } else {
                out.append(l).append(' ').appendln(depth[r])
            }
        } else {
            val curr = queryRMQ(l, r)
            val pos = queryRMQ(l + 1, r)
            if (pos != curr) {
                out.append(l).append(' ').appendln(depth[pos])
            } else {
                var upper = r
                var lower = l
                while (upper > lower) {
                    val mid = (upper + lower + 1) / 2
                    if (queryRMQ(l, mid) == curr) {
                        upper = mid - 1
                    } else {
                        lower = mid
                    }
                }
                if (upper in l until r) {
                    val pos = if (upper == r - 1) queryRMQ(l, r - 1) else lca(queryRMQ(l, upper), queryRMQ(upper + 2, r))
                    out.append(upper + 1).append(' ').appendln(depth[pos])
                } else {
                    out.append(r).append(' ').appendln(depth[curr])
                }
            }
        }
    }
    print(out)
}