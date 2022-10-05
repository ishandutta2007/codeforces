import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, q) = jin.readLine().split(" ").map { it.toInt() }
    val array = jin.readLine().split(" ").map { it.toLong() }
    val brray = jin.readLine().split(" ").map { it.toLong() }
    val sums = LongArray(m - n + 1)
    for (j in 0 until n) {
        if (j % 2 == 0) {
            sums[0] -= brray[j]
        } else {
            sums[0] += brray[j]
        }
    }
    for (j in 1..m - n) {
        sums[j] = -sums[j - 1] - brray[j - 1] + (if (n % 2 == 0) brray[n + j - 1] else -brray[n + j - 1])
    }
    var base = 0L
    for (j in 0 until n) {
        if (j % 2 == 0) {
            base += array[j]
        } else {
            base -= array[j]
        }
    }
    val treeSet = TreeSet<Long>(sums.toList())
    val out = StringBuilder()
    fun findAnswer() {
        var res = Long.MAX_VALUE
        var y = treeSet.floor(-base)
        if (y != null) {
            res = min(res, abs(y + base))
        }
        y = treeSet.ceiling(-base)
        if (y != null) {
            res = min(res, abs(y + base))
        }
        out.appendln(res)
    }
    findAnswer()
    for (j in 1..q) {
        val line = jin.readLine().split(" ")
        val from = line[0].toInt()
        val to = line[1].toInt()
        val x = line[2].toLong()
        if (to % 2 == 1) {
            base += x
        }
        if (from % 2 == 0) {
            base -= x
        }
        findAnswer()
    }
    print(out)
}