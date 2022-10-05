import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.system.exitProcess

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val judgements = Array(n) { jin.readLine() }
    val adjInitial = Array(n + m) { mutableListOf<Int>() }
    for (y in 0 until n) {
        for (x in 0 until m) {
            if (judgements[y][x] == '=') {
                adjInitial[y].add(n + x)
                adjInitial[n + x].add(y)
            }
        }
    }
    val union = IntArray(n + m)
    var j = 0
    val stack = Stack<Int>()
    for (r in 0 until n + m) {
        if (union[r] == 0) {
            j++
            union[r] = j
            stack.push(r)
            while (stack.isNotEmpty()) {
                val a = stack.pop()
                for (b in adjInitial[a]) {
                    if (union[b] == 0) {
                        union[b] = j
                        stack.push(b)
                    }
                }
            }
        }
    }
    val adj = Array(j + 1) { mutableSetOf<Int>() }
    for (y in 0 until n) {
        for (x in 0 until m) {
            if (judgements[y][x] != '=') {
                if (union[y] == union[n + x]) {
                    println("No")
                    return
                } else if (judgements[y][x] == '<') {
                    adj[union[n + x]].add(union[y])
                } else {
                    adj[union[y]].add(union[n + x])
                }
            }
        }
    }
    val memo = IntArray(j + 1)
    val beingCalled = BooleanArray(j + 1)
    fun getRating(a: Int): Int {
        if (beingCalled[a]) {
            println("No")
            exitProcess(0)
        }
        beingCalled[a] = true
        if (memo[a] == 0) {
            memo[a] = 1
            for (b in adj[a]) {
                memo[a] = max(memo[a], getRating(b) + 1)
            }
        }
        beingCalled[a] = false
        return memo[a]
    }
    for (a in 1..j) {
        getRating(a)
    }
    val out = StringBuilder()
    out.appendln("Yes")
    for (y in 0 until n) {
        out.append(memo[union[y]]).append(' ')
    }
    out.appendln()
    for (x in 0 until m) {
        out.append(memo[union[n + x]]).append(' ')
    }
    out.appendln()
    print(out)
}