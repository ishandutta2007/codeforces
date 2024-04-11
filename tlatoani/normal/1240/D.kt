import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val tokenizer = StringTokenizer(jin.readLine())
        val nodeStack = Stack<Trie>()
        nodeStack.push(Trie())
        nodeStack.peek().here++
        val numStack = Stack<Int>()
        numStack.push(0)
        var answer = 0L
        for (j in 1..n) {
            val k = tokenizer.nextToken().toInt()
            if (k == numStack.peek()) {
                numStack.pop()
                nodeStack.pop()
            } else {
                numStack.push(k)
                nodeStack.push(nodeStack.peek().children.computeIfAbsent(k) { Trie() })
            }
            answer += nodeStack.peek().here
            nodeStack.peek().here++
        }
        out.appendln(answer)
    }
    print(out)
}

class Trie {
    val children = mutableMapOf<Int, Trie>()
    var here = 0L
}