import java.util.*
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val episodes = intArrayOf(0) + IntArray(n) { min(n, tokenizer.nextToken().toInt()) }
    val seasons = Array(n) { it + 1 }
    seasons.sortByDescending { episodes[it] }
    var answer = 0L
    var k = 0
    val bit = BinaryIndexTree(1, n)
    for (j in n downTo 1) {
        while (k < n && episodes[seasons[k]] >= j) {
            bit.update(seasons[k], 1L)
            k++
        }
        answer += bit[1, episodes[j]]
        if (episodes[j] >= j) {
            answer--
        }
    }
    answer /= 2L
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