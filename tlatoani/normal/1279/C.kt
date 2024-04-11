import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var tokenizer = StringTokenizer(readLine()!!)
        val n = tokenizer.nextToken().toInt()
        val m = tokenizer.nextToken().toInt()
        tokenizer = StringTokenizer(readLine()!!)
        val inStack = IntArray(n + 1)
        val bit = BinaryIndexTree(1, n)
        for (j in 1..n) {
            inStack[tokenizer.nextToken().toInt()] = j
            bit.update(j, 1L)
        }
        tokenizer = StringTokenizer(readLine()!!)
        var largestIx = 0
        var answer = 0L
        for (j in 1..m) {
            val p = tokenizer.nextToken().toInt()
            bit.update(inStack[p], -1L)
            if (inStack[p] > largestIx) {
                answer += 2L * bit.query(1, inStack[p])
                largestIx = inStack[p]
            }
            answer++
        }
        println(answer)
    }
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