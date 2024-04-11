import kotlin.math.min

fun main() {
    val (n, t) = readLine()!!.split(" ").map { it.toInt() }
    val bit = BinaryIndexTree(1, n / 10)
    var k = readLine()!!.toInt()
    fun query(from: Int, to: Int): Int {
        println("? $from $to")
        return (to - from + 1) - readLine()!!.toInt()
    }
    for (x in 1..n / 10) {
        bit.update(x, query((10 * (x - 1)) + 1, 10 * x))
    }
    for (j in 1..t) {
        var upper = n / 10
        var lower = 0
        while (upper > lower) {
            val mid = (upper + lower + 1) / 2
            if (bit[1, mid] < k) {
                lower = mid
            } else {
                upper = mid - 1
            }
        }
        lower = (lower * 10) + 1
        upper = min(n, lower + 9)
        while (upper > lower) {
            val mid = (upper + lower) / 2
            if (query(1, mid) >= k) {
                upper = mid
            } else {
                lower = mid + 1
            }
        }
        println("! $lower")
        if (j < t) {
            bit.update((lower + 9) / 10, -1)
            k = readLine()!!.toInt()
        }
    }
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