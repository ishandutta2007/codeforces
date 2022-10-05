import java.util.*

const val MOD = 998244353L

fun main() {
    val n = readLine()!!.toInt()
    val intervals = arrayOf(Interval(0, 0, false)) + Array(n) {
        val (from, to, initial) = readLine()!!.split(" ").map { it.toInt() }
        Interval(from, to, initial == 1)
    }
    val treeMap = TreeMap<Int, Int>()
    for (k in 1..n) {
        treeMap[intervals[k].from] = k
    }
    var answer = (intervals[n].from + 1).toLong()
    val bit = BinaryIndexTree(1, n)
    for (k in 1..n) {
        val here = (bit[treeMap.higherEntry(intervals[k].to)!!.value, n] + intervals[k].length) % MOD
        if (intervals[k].active) {
            answer += here
        }
        bit.update(k, here)
    }
    answer %= MOD
    answer += MOD
    answer %= MOD
    println(answer)
}

data class Interval(val from: Int, val to: Int, val active: Boolean) {
    val length = (from - to).toLong()
}

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = LongArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Long) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            value[i] %= MOD
            i += i and -i
        }
    }

    fun query(to: Int): Long {
        var res = 0L
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            res %= MOD
            i -= i and -i
        }
        return res
    }

    operator fun get(from: Int, to: Int) = if (to < from) 0L else query(to) - query(from - 1)
}