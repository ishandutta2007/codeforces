import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        if (c > 1) {
            jin.readLine()
        }
        var tokenizer = StringTokenizer(jin.readLine())
        val n = tokenizer.nextToken().toInt()
        val m = tokenizer.nextToken().toInt()
        tokenizer = StringTokenizer(jin.readLine())
        val k = LongArray(n) { tokenizer.nextToken().toLong() }
        val adj = Array(n + 1) { mutableListOf<Int>() }
        for (j in 1..m) {
            tokenizer = StringTokenizer(jin.readLine())
            val a = tokenizer.nextToken().toInt()
            val b = tokenizer.nextToken().toInt()
            adj[b].add(a)
        }
        val root = Trie()
        for (a in 1..n) {
            if (adj[a].isEmpty()) {
                continue
            }
            adj[a].sort()
            var node = root
            for (b in adj[a]) {
                node = node.children.computeIfAbsent(b) { Trie() }
            }
            node.sum += k[a - 1]
        }
        var answer = 0L
        val stack = Stack<Trie>()
        stack.push(root)
        while (stack.isNotEmpty()) {
            val node = stack.pop()
            answer = gcd(answer, node.sum)
            for (next in node.children.values) {
                stack.push(next)
            }
        }
        out.appendln(answer)
    }
    print(out)
}

class Trie {
    val children = mutableMapOf<Int, Trie>()
    var sum = 0L
}

fun gcd(alpha: Long, beta: Long): Long {
    var a = max(alpha, beta)
    var b = min(alpha, beta)
    while (b != 0L) {
        a %= b
        if (a == 0L) {
            return b
        }
        b %= a
    }
    return a
}