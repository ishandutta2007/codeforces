import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val ay = (listOf(0) + jin.readLine().split(" ").map { it.toInt() }).toIntArray()
    val bit = BinaryIndexTree(1, n)
    val elements = mutableListOf<Element>()
    for (j in 1..n) {
        if (j - ay[j] >= 0 && bit[1, j] >= j - ay[j]) {
            var upper = j
            var lower = 1
            while (upper > lower) {
                val mid = (upper + lower + 1) / 2
                if (bit[mid, j] >= j - ay[j]) {
                    lower = mid
                } else {
                    upper = mid - 1
                }
            }
            bit.update(upper, 1)
            elements.add(Element(j, upper))
        }
    }
    elements.sortBy { it.req }
    bit.value.fill(0)
    for (elem in elements) {
        bit.update(elem.ix, 1)
    }
    val queries = Array(q) {
        val (x, y) = jin.readLine().split(" ").map { it.toInt() }
        Query(it, x + 1, n - y)
    }
    queries.sortBy { it.from }
    val answer = IntArray(q)
    var j = 0
    for (query in queries) {
        while (j < elements.size && elements[j].req < query.from) {
            bit.update(elements[j].ix, -1)
            j++
        }
        answer[query.ix] = bit[1, query.to]
    }
    println(answer.joinToString("\n"))
}

data class Element(val ix: Int, val req: Int)
data class Query(val ix: Int, val from: Int, val to: Int)

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