import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val costs = listOf(1000001L) + jin.readLine().split(" ").map { it.toLong() }
    val queries = Array(jin.readLine().toInt()) {
        val (l, r) = jin.readLine().split(" ").map { it.toInt() }
        Query(l, r, it)
    }
    queries.sortBy { it.to }
    val treeSet = TreeSet<Int>()
    treeSet.add(0)
    val answer = LongArray(queries.size)
    var r = 0
    val bit = BinaryIndexTree(1, n)
    for ((from, to, j) in queries) {
        while (r < to) {
            r++
            while (costs[r] >= costs[treeSet.last()]) {
                val k = treeSet.last()
                treeSet.remove(k)
                bit.update(k, -bit[k, k])
            }
            val k = treeSet.last()
            bit.update(r, (r - k).toLong() * costs[r])
            treeSet.add(r)
        }
        val k = treeSet.ceiling(from)
        answer[j] = ((k - from + 1).toLong() * costs[k]) + bit[k + 1, n]
    }
    println(answer.joinToString(" "))
}

data class Query(val from: Int, val to: Int, val index: Int)

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = LongArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Long) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Long {
        var res = 0L
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            i -= i and -i
        }
        return res
    }

    operator fun get(from: Int, to: Int) = if (to < from) 0L else query(to) - query(from - 1)
}