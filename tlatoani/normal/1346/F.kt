import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ").map { it.toInt() }
    val n = line[0]
    val m = line[1]
    val q = line[2]
    val grid = arrayOf(mutableListOf<Long>()) + Array(n) { ("0 " + jin.readLine()).split(" ").map { it.toLong() }.toMutableList() }
    val verticalBIT = BinaryIndexTree(1, n + 1)
    val horizontalBIT = BinaryIndexTree(1, m + 1)
    val verticalBITDists = BinaryIndexTree(1, n + 1)
    val horizontalBITDists = BinaryIndexTree(1, m + 1)
    var currSum = 0L
    for (y in 1..n) {
        for (x in 1..m) {
            verticalBIT.update(y, grid[y][x])
            verticalBITDists.update(y, y.toLong() * grid[y][x])
            horizontalBIT.update(x, grid[y][x])
            horizontalBITDists.update(x, x.toLong() * grid[y][x])
            currSum += grid[y][x]
        }
    }
    val joiner = StringJoiner(" ")
    fun findAnswer() {
        var upper = n
        var lower = 1
        while (upper > lower) {
            val mid = (upper + lower) / 2
            if (verticalBIT[1, mid] >= (currSum + 1L) / 2L) {
                upper = mid
            } else {
                lower = mid + 1
            }
        }
        val y = upper
        upper = m
        lower = 1
        while (upper > lower) {
            val mid = (upper + lower) / 2
            if (horizontalBIT[1, mid] >= (currSum + 1L) / 2L) {
                upper = mid
            } else {
                lower = mid + 1
            }
        }
        val x = upper
        var res = (verticalBIT[1, y] * y.toLong()) - verticalBITDists[1, y]
        res += verticalBITDists[y + 1, n] - (verticalBIT[y + 1, n] * y.toLong())
        res += (horizontalBIT[1, x] * x.toLong()) - horizontalBITDists[1, x]
        res += horizontalBITDists[x + 1, m] - (horizontalBIT[x + 1, m] * x.toLong())
        joiner.add(res.toString())
    }
    findAnswer()
    for (j in 1..q) {
        val line = jin.readLine().split(" ")
        val y = line[0].toInt()
        val x = line[1].toInt()
        val z = line[2].toLong()
        currSum += z - grid[y][x]
        verticalBIT.update(y, z - grid[y][x])
        verticalBITDists.update(y, (z - grid[y][x]) * y.toLong())
        horizontalBIT.update(x, z - grid[y][x])
        horizontalBITDists.update(x, (z - grid[y][x]) * x.toLong())
        grid[y][x] = z
        findAnswer()
    }
    println(joiner)
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