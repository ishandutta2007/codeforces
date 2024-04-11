import java.util.*
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val root = Trie()
    for (j in 1..n) {
        val a = tokenizer.nextToken().toInt()
        var node = root
        for (e in 29 downTo 0) {
            if (((a shr e) and 1) == 0) {
                node = node.left()
            } else {
                node = node.right()
            }
        }
    }
    println(root.calc(0))
}

class Trie {
    var left: Trie? = null
    var right: Trie? = null

    fun left(): Trie {
        if (left == null) {
            left = Trie()
        }
        return left!!
    }

    fun right(): Trie {
        if (right == null) {
            right = Trie()
        }
        return right!!
    }

    fun calc(prev: Int): Int {
        if (left == null) {
            if (right == null) {
                return prev
            } else {
                return right!!.calc(prev * 2)
            }
        } else {
            if (right == null) {
                return left!!.calc(prev * 2)
            } else {
                return min(left!!.calc((prev * 2) + 1), right!!.calc((prev * 2) + 1))
            }
        }
    }
}