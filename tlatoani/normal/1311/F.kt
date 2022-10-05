import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    var tokenizer = StringTokenizer(readLine()!!)
    val xs = IntArray(n) { tokenizer.nextToken().toInt() }
    tokenizer = StringTokenizer(readLine()!!)
    val ps = Array(n) { Pair(xs[it], tokenizer.nextToken().toInt()) }
    ps.sortBy { it.first }
    val ts1 = TrieSum(-100000001, 100000001)
    val ts2 = TrieSum(-100000001, 100000001)
    var answer = 0L
    for (p in ps) {
        //println("p = $p, answer = $answer")
        answer += (p.first.toLong() * ts1.sumAtMost(p.second)) - ts2.sumAtMost(p.second)
        ts1.add(p.second, 1)
        ts2.add(p.second, p.first.toLong())
    }
    println(answer)
}

class TrieSum(val treeFrom: Int, treeTo: Int) {
    val root = Node()
    val height: Int
    fun add(k: Int, delta: Long) {
        var k = k
        k -= treeFrom
        var node: Node? = root
        for (e in height - 1 downTo 0) {
            if (k shr e and 1 == 0) {
                if (node!!.left == null) {
                    node.left = Node()
                }
                node = node.left
            } else {
                if (node!!.right == null) {
                    node.right = Node()
                }
                node = node.right
            }
            node!!.subTreeSum += delta
        }
    }

    fun sumAtMost(k: Int): Long {
        var k = k
        var res: Long = 0
        k -= treeFrom
        var node: Node? = root
        var e = height - 1
        while (e >= 0 && node != null) {
            if (k shr e and 1 == 0) {
                node = node.left
            } else {
                if (node.left != null) {
                    res += node.left!!.subTreeSum
                }
                node = node.right
            }
            e--
        }
        if (node != null) {
            res += node.subTreeSum
        }
        return res
    }

    fun sumAtLeast(k: Int): Long {
        var k = k
        var res: Long = 0
        k -= treeFrom
        var node: Node? = root
        var e = height - 1
        while (e >= 0 && node != null) {
            if (k shr e and 1 == 0) {
                if (node.right != null) {
                    res += node.right!!.subTreeSum
                }
                node = node.left
            } else {
                node = node.right
            }
            e--
        }
        if (node != null) {
            res += node.subTreeSum
        }
        return res
    }

    class Node {
        var left: Node? = null
        var right: Node? = null
        var subTreeSum: Long = 0
    }

    init {
        val size = treeTo - treeFrom + 1
        var height = 0
        while (1 shl height < size) {
            height++
        }
        this.height = height
    }
}