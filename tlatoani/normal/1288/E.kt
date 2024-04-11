import java.util.*
import kotlin.math.max

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val m = line.substring(six + 1).toInt()
    val lowest = IntArray(n + 1) { it }
    val highest = IntArray(n + 1) { it }
    val pos = IntArray(n + 1) { it }
    val bit = BinaryIndexTree(1 - m, n)
    for (j in 1..n) {
        bit.update(j, 1)
    }
    val tokenizer = StringTokenizer(readLine()!!)
    for (j in 1..m) {
        val k = tokenizer.nextToken().toInt()
        highest[k] = max(highest[k], bit.query(1 - m, pos[k]).toInt())
        bit.update(pos[k], -1)
        pos[k] = 1 - j
        bit.update(pos[k], 1)
        lowest[k] = 1
    }
    val out = StringBuilder()
    for (j in 1..n) {
        highest[j] = max(highest[j], bit.query(1 - m, pos[j]).toInt())
        out.append(lowest[j]).append(' ').appendln(highest[j])
    }
    print(out)
}

class BinaryIndexTree(treeFrom: Int, treeTo: Int) {
    val `val`: LongArray
    val treeFrom: Int
    fun update(index: Int, delta: Long) {
        var i = index + 1 - treeFrom
        while (i < `val`.size) {
            `val`[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Long {
        var res: Long = 0
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += `val`[i]
            i -= i and -i
        }
        return res
    }

    fun query(from: Int, to: Int): Long {
        return if (to < from) {
            0
        } else query(to) - query(from - 1)
    }

    init {
        `val` = LongArray(treeTo - treeFrom + 2)
        this.treeFrom = treeFrom
    }
}