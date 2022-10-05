import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val ay = readLine()!!.split(" ").map { it.toInt() }
        var j = 0
        val xix = mutableMapOf<Int, Int>()
        for (x in ay.toSet().sorted()) {
            j++
            xix[x] = j
        }
        val bit = BinaryIndexTree(1, j)
        var answer = 0L
        for (x in ay) {
            val k = xix[x]!!
            answer += min(bit[1, k - 1], bit[k + 1, j])
            bit.update(k, 1L)
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