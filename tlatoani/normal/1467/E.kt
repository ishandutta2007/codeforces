import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val ay = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        adj[a].add(b)
        adj[b].add(a)
    }
    val ls = IntArray(n + 1)
    val rs = IntArray(n + 1)
    var k = 0
    fun recur(a: Int) {
        k++
        ls[a] = k
        for (b in adj[a]) {
            if (ls[b] == 0) {
                recur(b)
            }
        }
        rs[a] = k
    }
    recur(1)
    val bit1 = BinaryIndexTree(1, n)
    val bit2 = BinaryIndexTree(1, n + 1)
    val nodes = (1..n).sortedBy { ay[it] }
    var j1 = 0
    while (j1 < n) {
        val here = mutableListOf<Int>()
        var j2 = j1
        while (j2 < n && ay[nodes[j2]] == ay[nodes[j1]]) {
            here.add(nodes[j2])
            j2++
        }
        for (a in here) {
            bit1.update(ls[a], 1)
        }
        for (a in here) {
            val subtree = bit1[ls[a], rs[a]]
            if (subtree > 1) {
                bit2.update(1, 1)
                bit2.update(ls[a] + 1, -1)
                bit2.update(rs[a] + 1, 1)
            }
            if (here.size > subtree) {
                bit2.update(ls[a], 1)
                bit2.update(rs[a] + 1, -1)
            }
            for (b in adj[a]) {
                if (ls[b] > ls[a]) {
                    if (bit1[ls[b], rs[b]] + 1 != subtree) {
                        bit2.update(ls[b], 1)
                        bit2.update(rs[b] + 1, -1)
                    }
                }
            }
        }
        for (a in here) {
            bit1.update(ls[a], -1)
        }
        j1 = j2
    }
    println((1..n).count { bit2[1, ls[it]] == 0 })
}

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = IntArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Int) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Int {
        var res = 0
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            i -= i and -i
        }
        return res
    }

    operator fun get(from: Int, to: Int) = if (to < from) 0 else query(to) - query(from - 1)
}