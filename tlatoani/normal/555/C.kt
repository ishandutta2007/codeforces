import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, q) = jin.readLine().split(" ").map { it.toInt() }
    val xSet = mutableSetOf(0)
    val queries = Array(q) {
        val line = jin.readLine().split(" ")
        val x = line[0].toInt()
        val y = line[1].toInt()
        val up = line[2][0] == 'U'
        xSet.add(x)
        xSet.add(y)
        Query(if (up) x else y, up)
    }
    val xs = xSet.toList().sorted()
    val xix = mutableMapOf<Int, Int>()
    for (j in xs.indices) {
        xix[xs[j]] = j
    }
    val upSegTree = SegmentTree(0, xs.size)
    upSegTree[0] = 0
    val leftSegTree = SegmentTree(0, xs.size)
    leftSegTree[0] = 0
    val out = StringBuilder()
    for (query in queries) {
        if (query.up) {
            val x = xix[query.z]!!
            if (upSegTree[x] == Int.MAX_VALUE) {
                val y = xix[n + 1 - query.z]!!
                var upper = y
                var lower = 0
                while (upper > lower) {
                    val mid = (upper + lower + 1) / 2
                    if (leftSegTree[mid, y] <= x) {
                        lower = mid
                    } else {
                        upper = mid - 1
                    }
                }
                out.appendln(n + 1 - query.z - xs[upper])
                upSegTree[x] = upper + 1
            } else {
                out.appendln(0)
            }
        } else {
            val y = xix[query.z]!!
            if (leftSegTree[y] == Int.MAX_VALUE) {
                val x = xix[n + 1 - query.z]!!
                var upper = x
                var lower = 0
                while (upper > lower) {
                    val mid = (upper + lower + 1) / 2
                    if (upSegTree[mid, x] <= y) {
                        lower = mid
                    } else {
                        upper = mid - 1
                    }
                }
                out.appendln(n + 1 - query.z - xs[upper])
                leftSegTree[y] = upper + 1
            } else {
                out.appendln(0)
            }
        }
    }
    print(out)
}

data class Query(val z: Int, val up: Boolean)

class SegmentTree(val treeFrom: Int, treeTo: Int) {
    val value: IntArray
    val length: Int

    init {
        var e = 0
        while (1 shl e < treeTo - treeFrom + 1) {
            e++
        }
        value = IntArray(1 shl (e + 1)) { Int.MAX_VALUE }
        length = 1 shl e
    }

    operator fun set(index: Int, delta: Int) {
        var node = index - treeFrom + length
        value[node] = delta
        node = node shr 1
        while (node > 0) {
            value[node] = min(value[node shl 1], value[(node shl 1) + 1])
            node = node shr 1
        }
    }

    operator fun get(index: Int) = value[index - treeFrom + length]

    operator fun get(fromIndex: Int, toIndex: Int): Int {
        if (toIndex < fromIndex) {
            return Int.MAX_VALUE
        }
        var from = fromIndex + length - treeFrom
        var to = toIndex + length - treeFrom + 1
        var res: Int = Int.MAX_VALUE
        while (from + (from and -from) <= to) {
            res = min(res, value[from / (from and -from)])
            from += from and -from
        }
        while (to - (to and -to) >= from) {
            res = min(res, value[(to - (to and -to)) / (to and -to)])
            to -= to and -to
        }
        return res
    }
}