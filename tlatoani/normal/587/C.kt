import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, q) = jin.readLine().split(" ").map { it.toInt() }
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(b)
        adj[b].add(a)
    }
    val parent = Array(17) { IntArray(n + 1) }
    val depth = IntArray(n + 1)
    val people = Array(n + 1) { mutableListOf<Int>() }
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..m) {
        people[tokenizer.nextToken().toInt()].add(j)
    }
    val l1 = IntArray(n + 1)
    val l2 = IntArray(n + 1)
    val order = mutableListOf<Int>()
    fun recur(a: Int) {
        l1[a] = order.size
        for (p in people[a]) {
            order.add(p)
        }
        l2[a] = order.size - 1
        for (b in adj[a]) {
            parent[0][b] = a
            for (e in 1..16) {
                parent[e][b] = parent[e - 1][parent[e - 1][b]]
            }
            depth[b] = depth[a] + 1
            adj[b].remove(a)
            recur(b)
        }
        for (p in people[a]) {
            order.add(p)
        }
    }
    recur(1)
    val dummy = Query(0, 0, 0, 0)
    val queries = Array(2 * q) { dummy }
    fun lca(a: Int, b: Int): Int {
        var a = a
        var b = b
        if (depth[a] > depth[b]) {
            val c = a
            a = b
            b = c
        }
        for (e in 16 downTo 0) {
            if (depth[b] - depth[a] >= 1 shl e) {
                b = parent[e][b]
            }
        }
        if (b == a) {
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
    for (j in 0 until q) {
        val (a, b, limit) = jin.readLine().split(" ").map { it.toInt() }
        val c = lca(a, b)
        queries[2 * j] = Query(j, l1[c], l2[a], limit)
        queries[(2 * j) + 1] = Query(j, l1[c], l2[b], limit)
    }
    queries.sortWith(compareBy({ it.from / 500 }, { it.to }))
    val answer = Array(q) { mutableListOf<Int>() }
    val seen = BooleanArray(q)
    val en = BooleanArray(q + 1)
    en[order[0]] = true
    val bit = BinaryIndexTree(1 shl 17)
    bit.increment(order[0])
    var from = 0
    var to = 0
    for (query in queries) {
        if (query.from <= query.to) {
            while (query.from < from) {
                from--
                if (en[order[from]]) {
                    en[order[from]] = false
                    bit.decrement(order[from])
                } else {
                    en[order[from]] = true
                    bit.increment(order[from])
                }
            }
            while (to < query.to) {
                to++
                if (en[order[to]]) {
                    en[order[to]] = false
                    bit.decrement(order[to])
                } else {
                    en[order[to]] = true
                    bit.increment(order[to])
                }
            }
            while (to > query.to) {
                if (en[order[to]]) {
                    en[order[to]] = false
                    bit.decrement(order[to])
                } else {
                    en[order[to]] = true
                    bit.increment(order[to])
                }
                to--
            }
            while (query.from > from) {
                if (en[order[from]]) {
                    en[order[from]] = false
                    bit.decrement(order[from])
                } else {
                    en[order[from]] = true
                    bit.increment(order[from])
                }
                from++
            }
            val limit = min(query.limit, bit.value[1 shl 17])
            for (j in 1..limit) {
                var p = 0
                var rem = j
                for (e in 16 downTo 0) {
                    val add = bit.value[p + (1 shl e)]
                    if (add < rem) {
                        p += 1 shl e
                        rem -= add
                    }
                }
                p++
                answer[query.ix].add(p)
            }
            if (seen[query.ix]) {
                val new = mutableListOf<Int>()
                answer[query.ix].sort()
                for (p in answer[query.ix]) {
                    if (new.isEmpty() || p != new.last()) {
                        new.add(p)
                    }
                    if (new.size == query.limit) {
                        break
                    }
                }
                answer[query.ix] = new
            } else {
                seen[query.ix] = true
            }
        }
    }
    val out = StringBuilder()
    for (j in 0 until q) {
        out.append(answer[j].size)
        for (p in answer[j]) {
            out.append(' ').append(p)
        }
        out.appendln()
    }
    print(out)
}

data class Query(val ix: Int, val from: Int, val to: Int, val limit: Int)

class BinaryIndexTree(treeTo: Int) {
    val value = IntArray(treeTo + 1)

    fun increment(index: Int) {
        var i = index
        while (i < value.size) {
            value[i]++
            i += i and -i
        }
    }

    fun decrement(index: Int) {
        var i = index
        while (i < value.size) {
            value[i]--
            i += i and -i
        }
    }
}