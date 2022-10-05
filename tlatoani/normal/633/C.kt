import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val s = jin.readLine()
    val m = jin.readLine().toInt()
    val root = Trie()
    for (j in 1..m) {
        var node = root
        val w = jin.readLine()
        for (chara in w) {
            node = node.children.computeIfAbsent(chara.toLowerCase()) { Trie() }
        }
        node.word = w
    }
    val dp = IntArray(n + 1) { -1 }
    val dpWord = Array(n + 1) { "" }
    dp[0] = -2
    for (j in 1..n) {
        var node: Trie? = root
        for (k in j - 1 downTo 0) {
            node = node!!.children[s[k]]
            if (node == null) {
                break
            }
            if (node.word != null && dp[k] != -1) {
                dp[j] = k
                dpWord[j] = node.word!!
                break
            }
        }
    }
    val stack = Stack<String>()
    var j = n
    while (j != 0) {
        stack.push(dpWord[j])
        j = dp[j]
    }
    val answer = StringJoiner(" ")
    while (stack.isNotEmpty()) {
        answer.add(stack.pop())
    }
    println(answer)
}

class Trie {
    val children = mutableMapOf<Char, Trie>()
    var word: String? = null
}