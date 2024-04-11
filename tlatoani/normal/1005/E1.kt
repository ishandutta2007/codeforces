import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val ay = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    var answer = (n.toLong() * (n + 1).toLong()) / 2L
    val bit = BinaryIndexTree(-100000, 200000)
    var curr = 0
    bit.update(0, 1L)
    for (j in 1..n) {
        if (ay[j] < m) {
            curr++
        }
        if (j % 2 == 1) {
            curr--
        }
        answer -= bit.query(curr)
        if (j % 2 == 0) {
            bit.update(curr, 1L)
        }
    }
    bit.value.fill(0L)
    curr = 0
    for (j in 1..n) {
        if (ay[j] < m) {
            curr++
        }
        if (j % 2 == 0) {
            curr--
        }
        answer -= bit.query(curr)
        if (j % 2 == 1) {
            bit.update(curr, 1L)
        }
    }
    bit.value.fill(0L)
    curr = 0
    bit.update(0, 1L)
    for (j in 1..n) {
        if (ay[j] > m) {
            curr++
        }
        if (j % 2 == 0) {
            curr--
        }
        answer -= bit.query(curr - 1)
        if (j % 2 == 0) {
            bit.update(curr, 1L)
        }
    }
    bit.value.fill(0L)
    curr = 0
    for (j in 1..n) {
        if (ay[j] > m) {
            curr++
        }
        if (j % 2 == 1) {
            curr--
        }
        answer -= bit.query(curr - 1)
        if (j % 2 == 1) {
            bit.update(curr, 1L)
        }
    }
    println(answer)
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