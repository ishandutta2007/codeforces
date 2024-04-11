import java.util.*

fun main() {
    val (n, q) = readLine()!!.split(" ").map { it.toInt() }
    val out = StringBuilder()
    val ay = (listOf(Int.MAX_VALUE) + readLine()!!.split(" ").map { it.toInt() } + listOf(0)).toIntArray()
    val bit = BinaryIndexTree(1, n)
    val breaks = TreeSet<Int>()
    breaks.add(1)
    for (j in 2..n + 1) {
        if (ay[j - 1] > ay[j]) {
            val prev = breaks.last()
            val length = (j - prev).toLong()
            bit.update(prev, (length * (length + 1L)) / 2L)
            breaks.add(j)
        }
    }
    fun removeBreak(j: Int) {
        if (j != 1 && j != n + 1 && ay[j - 1] > ay[j]) {
            breaks.remove(j)
            val prev = breaks.lower(j)!!
            val next = breaks.higher(j)!!
            val length1 = (j - prev).toLong()
            val length2 = (next - j).toLong()
            val lengthTotal = (next - prev).toLong()
            bit.update(prev, -(length1 * (length1 + 1L)) / 2L)
            bit.update(j, -(length2 * (length2 + 1L)) / 2L)
            bit.update(prev, (lengthTotal * (lengthTotal + 1L)) / 2L)
        }
    }
    fun addBreak(j: Int) {
        if (j != 1 && j != n + 1 && ay[j - 1] > ay[j]) {
            val prev = breaks.lower(j)!!
            val next = breaks.higher(j)!!
            val length1 = (j - prev).toLong()
            val length2 = (next - j).toLong()
            val lengthTotal = (next - prev).toLong()
            bit.update(prev, -(lengthTotal * (lengthTotal + 1L)) / 2L)
            bit.update(prev, (length1 * (length1 + 1L)) / 2L)
            bit.update(j, (length2 * (length2 + 1L)) / 2L)
            breaks.add(j)
        }
    }
    repeat(q) {
        val line = readLine()!!.split(" ").map { it.toInt() }
        if (line[0] == 1) {
            val (_, x, y) = line
            removeBreak(x)
            removeBreak(x + 1)
            ay[x] = y
            addBreak(x)
            addBreak(x + 1)
        } else {
            val (_, l, r) = line
            if (breaks.ceiling(l)!! > r) {
                val length = (r - l + 1).toLong()
                out.appendln((length * (length + 1L)) / 2L)
            } else {
                var res = bit[l, r]
                val atLeft = (breaks.ceiling(l)!! - l).toLong()
                res += (atLeft * (atLeft + 1L)) / 2L
                val rightStart = breaks.floor(r)!!
                val rightEnd = breaks.higher(r)!!
                val originalLength = (rightEnd - rightStart).toLong()
                res -= (originalLength * (originalLength + 1L)) / 2L
                val newLength = (r - rightStart + 1).toLong()
                res += (newLength * (newLength + 1L)) / 2L
                out.appendln(res)
            }
        }
    }
    print(out)
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