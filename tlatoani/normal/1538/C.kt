import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, l, r) = readLine()!!.split(" ").map { it.toInt() }
        val ay = readLine()!!.split(" ").map { it.toInt() }
        val treeMap = TreeMap<Int, Int>()
        for (x in ay) {
            treeMap[x] = -x
        }
        var ix = 0
        for (x in treeMap.keys.toList()) {
            ix++
            treeMap[x] = ix
        }
        treeMap[Int.MIN_VALUE] = 0
        treeMap[Int.MAX_VALUE] = n + 1
        val bit = BinaryIndexTree(0, n + 1)
        var answer = 0L
        for (x in ay) {
            val from = treeMap.ceilingEntry(l - x).value
            val to = treeMap.floorEntry(r - x).value
            answer += bit[from, to]
            bit.update(treeMap[x]!!, 1L)
        }
        println(answer)
    }
}

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