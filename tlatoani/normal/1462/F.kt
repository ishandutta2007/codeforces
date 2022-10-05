import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val segments = Array(n) { jin.readLine().split(" ").map { it.toInt() } }
        val zs = mutableSetOf<Int>()
        for ((l, r) in segments) {
            zs.add(l)
            zs.add(r + 1)
        }
        val zix = mutableMapOf<Int, Int>()
        for ((j, z) in zs.toList().sorted().withIndex()) {
            zix[z] = j + 1
        }
        segments.sortWith(compareBy({ it[0] }, { -it[1] }))
        val bit = BinaryIndexTree(1, zix.size)
        for ((l, r) in segments) {
            bit.update(zix[l]!!, 1)
        }
        var curr = 0
        val pq = PriorityQueue<Int>()
        var answer = n - 1
        for ((l, r) in segments) {
            while (pq.isNotEmpty() && pq.peek() < l) {
                pq.remove()
                curr--
            }
            answer = min(answer, n - curr - bit[zix[l]!!, zix[r + 1]!! - 1])
            bit.update(zix[l]!!, -1)
            curr++
            pq.add(r)
        }
        out.appendln(answer)
    }
    print(out)
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