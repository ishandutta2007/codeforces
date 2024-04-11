import java.util.*

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(readLine()!!)
    val bags1 = Array((2 * n) + 1) { TrieBag(-1, 2 * n) }
    val bags2 = Array((2 * n) + 1) { TrieBag(-1, 2 * n) }
    var curr1 = n
    var curr2 = n
    var currAmt = 0L
    var answer = 0L
    for (j in 0 until n) {
        bags1[curr1].add(curr2)
        bags2[curr2].add(curr1)
        val a = tokenizer.nextToken().toInt()
        if (a < m) {
            curr1--
            currAmt -= bags1[curr1].amtAtLeast(curr2)
        } else {
            curr1++
            currAmt += bags1[curr1 - 1].amtAtLeast(curr2)
        }
        if (a <= m) {
            curr2--
            currAmt += bags2[curr2].amtAtMost(curr1 - 1)
        } else {
            curr2++
            currAmt -= bags2[curr2 - 1].amtAtMost(curr1 - 1)
        }
        answer += currAmt
    }
    println(answer)
}

class TrieBag(val treeFrom: Int, treeTo: Int) {
    val root = Node()
    val height: Int
    fun add(k: Int) {
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
            node!!.subTreeSize++
        }
    }

    fun amtAtMost(k: Int): Int {
        var k = k
        var res = 0
        k -= treeFrom
        var node: Node? = root
        var e = height - 1
        while (e >= 0 && node != null) {
            if (k shr e and 1 == 0) {
                node = node.left
            } else {
                if (node.left != null) {
                    res += node.left!!.subTreeSize
                }
                node = node.right
            }
            e--
        }
        if (node != null) {
            res += node.subTreeSize
        }
        return res
    }

    fun amtAtLeast(k: Int): Int {
        var k = k
        var res = 0
        k -= treeFrom
        var node: Node? = root
        var e = height - 1
        while (e >= 0 && node != null) {
            if (k shr e and 1 == 0) {
                if (node.right != null) {
                    res += node.right!!.subTreeSize
                }
                node = node.left
            } else {
                node = node.right
            }
            e--
        }
        if (node != null) {
            res += node.subTreeSize
        }
        return res
    }

    class Node {
        var left: Node? = null
        var right: Node? = null
        var subTreeSize = 0
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