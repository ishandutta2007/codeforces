import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj0 = Array(n + 1) { mutableSetOf<Int>() }
    val adj1 = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        val tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        if (tokenizer.nextToken().toInt() == 1) {
            adj0[a].add(b)
            adj0[b].add(a)
        } else {
            adj1[a].add(b)
            adj1[b].add(a)
        }
    }
    val ancestor= IntArray(n + 1)
    val stack = Stack<Int>()
    stack.push(1)
    val answer = mutableSetOf<Int>()
    while (!stack.isEmpty()) {
        val a = stack.pop()
        for (b in adj0[a]) {
            adj0[b].remove(a)
            ancestor[b] = ancestor[a]
            stack.push(b)
        }
        for (b in adj1[a]) {
            adj1[b].remove(a)
            answer.remove(ancestor[a])
            ancestor[b] = b
            answer.add(b)
            stack.push(b)
        }
    }
    println(answer.size)
    println(answer.joinToString(" "))
}