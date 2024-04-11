import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj0 = Array(n + 1) { mutableListOf<Int>() }
    val adj1 = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        val tokenizer = StringTokenizer(jin.readLine())
        val a = tokenizer.nextToken().toInt()
        val b = tokenizer.nextToken().toInt()
        val color = tokenizer.nextToken().toInt()
        if (color == 0) {
            adj0[a].add(b)
            adj0[b].add(a)
        } else {
            adj1[a].add(b)
            adj1[b].add(a)
        }
    }
    val amts = IntArray(n + 1)
    val stack = Stack<Int>()
    for (r in 1..n) {
        if (amts[r] == 0) {
            amts[r] = -1
            val component = mutableListOf<Int>()
            stack.push(r)
            while (stack.isNotEmpty()) {
                val a = stack.pop()
                component.add(a)
                for (b in adj1[a]) {
                    if (amts[b] == 0) {
                        amts[b] = -1
                        stack.push(b)
                    }
                }
            }
            for (a in component) {
                amts[a] = component.size
            }
        }
    }
    var answer = -n.toLong()
    for (r in 1..n) {
        if (amts[r] != 0) {
            var amt = 1
            var sum = amts[r]
            amts[r] = 0
            stack.push(r)
            while (stack.isNotEmpty()) {
                val a = stack.pop()
                for (b in adj0[a]) {
                    if (amts[b] != 0) {
                        amt++
                        sum += amts[b]
                        amts[b] = 0
                        stack.push(b)
                    }
                }
            }
            answer += amt.toLong() * sum.toLong()
        }
    }
    println(answer)
}