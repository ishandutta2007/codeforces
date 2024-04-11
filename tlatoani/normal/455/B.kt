import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine()
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val k = line.substring(six + 1).toInt()
    val root = Trie()
    for (j in 1..n) {
        var node = root
        for (chara in jin.readLine()) {
            node = node.children.computeIfAbsent(chara) { Trie() }
        }
    }
    val stack = Stack<Trie>()
    stack.push(root)
    while (stack.isNotEmpty()) {
        val node = stack.pop()
        if (node.dp0 == -1) {
            node.dp0 = 0
            node.dp1 = if (node.children.isEmpty()) 1 else 0
            stack.push(node)
            for (child in node.children.values) {
                stack.push(child)
            }
        } else {
            for (child in node.children.values) {
                if (child.dp0 == 0) {
                    node.dp0 = 1
                }
                if (child.dp1 == 0) {
                    node.dp1 = 1
                }
            }
        }
    }
    if (root.dp0 == 0) {
        println("Second")
    } else {
        if (root.dp1 == 0) {
            println(if (k % 2 == 0) "Second" else "First")
        } else {
            println("First")
        }
    }
}

class Trie {
    val children = mutableMapOf<Char, Trie>()
    var dp0 = -1
    var dp1 = -1
}