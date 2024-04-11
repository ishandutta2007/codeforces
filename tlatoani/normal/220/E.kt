import java.util.*

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    val k = tokenizer.nextToken().toLong()
    tokenizer = StringTokenizer(readLine()!!)
    val array = Array(n) { tokenizer.nextToken().toInt() }
    val xs = TreeSet<Int>()
    xs.addAll(array)
    var ix = 0
    val xix = mutableMapOf<Int, Int>()
    for (x in xs) {
        ix++
        xix[x] = ix
    }
    val leftBIT = BinaryIndexTree(1, ix)
    val rightBIT = BinaryIndexTree(1, ix)
    var answer = 0L
    var curr = 0L
    for (j in 0 until n) {
        val jx = xix[array[j]]!!
        curr += rightBIT.query(jx + 1, ix)
        rightBIT.update(jx, 1L)
    }
    var r = 0
    for (l in 0 until n) {
        var jx = xix[array[l]]!!
        if (r == l) {
            rightBIT.update(jx, -1L)
            r++
        } else {
            curr += leftBIT.query(jx + 1, ix)
            curr += rightBIT.query(1, jx - 1)
        }
        leftBIT.update(jx, 1L)
        while (r < n && curr > k) {
            jx = xix[array[r]]!!
            curr -= leftBIT.query(jx + 1, ix)
            curr -= rightBIT.query(1, jx - 1)
            rightBIT.update(jx, -1L)
            r++
        }
        answer += (n - r).toLong()
    }
    println(answer)
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
            0L
        } else query(to) - query(from - 1)
    }

    init {
        `val` = LongArray(treeTo - treeFrom + 2)
        this.treeFrom = treeFrom
    }
}