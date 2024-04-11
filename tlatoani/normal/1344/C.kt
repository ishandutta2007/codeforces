import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    val rev = Array(n + 1) { mutableListOf<Int>() }
    for (j in 1..m) {
        val line = jin.readLine().split(" ")
        val a = line[0].toInt()
        val b = line[1].toInt()
        adj[a].add(b)
        rev[b].add(a)
    }
    val stack = Stack<Int>()
    val seenForward = BooleanArray(n + 1)
    val inRecursion = BooleanArray(n + 1)
    fun existsCycle(a: Int): Boolean {
        inRecursion[a] = true
        for (b in adj[a]) {
            if (inRecursion[b]) {
                return true
            } else if (!seenForward[b]) {
                seenForward[b] = true
                if (existsCycle(b)) {
                    return true
                }
            }
        }
        inRecursion[a] = false
        return false
    }
    for (r in 1..n) {
        if (!seenForward[r] && existsCycle(r)) {
            println(-1)
            return
        }
    }
    val answer = StringBuilder()
    seenForward.fill(false)
    val seenBackward = BooleanArray(n + 1)
    for (r in 1..n) {
        if (seenForward[r] || seenBackward[r]) {
            answer.append('E')
        } else {
            answer.append('A')
        }
        if (!seenForward[r]) {
            seenForward[r] = true
            stack.push(r)
            while (stack.isNotEmpty()) {
                val a = stack.pop()
                for (b in adj[a]) {
                    if (!seenForward[b]) {
                        seenForward[b] = true
                        stack.push(b)
                    }
                }
            }
        }
        if (!seenBackward[r]) {
            seenBackward[r] = true
            stack.push(r)
            while (stack.isNotEmpty()) {
                val a = stack.pop()
                for (b in rev[a]) {
                    if (!seenBackward[b]) {
                        seenBackward[b] = true
                        stack.push(b)
                    }
                }
            }
        }
    }
    println(answer.count { it == 'A' })
    println(answer)
}