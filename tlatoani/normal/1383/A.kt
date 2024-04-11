import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    cases@for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val a = jin.readLine()
        val b = jin.readLine()
        val adj = Array(20) { mutableSetOf<Int>() }
        for (j in 0 until n) {
            if (b[j] < a[j]) {
                println(-1)
                continue@cases
            } else {
                adj[a[j] - 'a'].add(b[j] - 'a')
                adj[b[j] - 'a'].add(a[j] - 'a')
            }
        }
        var answer = 20
        val seen = BooleanArray(20)
        val stack = Stack<Int>()
        for (r in 0..19) {
            if (!seen[r]) {
                answer--
                seen[r] = true
                stack.push(r)
                while (stack.isNotEmpty()) {
                    val x = stack.pop()
                    for (y in adj[x]) {
                        if (!seen[y]) {
                            seen[y] = true
                            stack.push(y)
                        }
                    }
                }
            }
        }
        println(answer)
    }
}

data class Path(val from: Int, val to: Int)