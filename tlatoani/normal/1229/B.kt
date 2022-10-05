import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

const val MOD = 1000000007

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val tokenizer = StringTokenizer(jin.readLine())
    val x = LongArray(n) { tokenizer.nextToken().toLong() }
    val children = Array(n) { mutableListOf<Int>() }
    val parent = IntArray(n) { -1 }
    for (j in 2..n) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt() - 1
        val b = line.substring(six + 1).toInt() - 1
        children[a].add(b)
        children[b].add(a)
    }
    val stack = Stack<Int>()
    stack.push(0)
    var changes = Array(n) { mutableListOf<Pair<Int, Long>>() }
    val d = IntArray(n)
    var answer = 0L
    while (!stack.isEmpty()) {
        val j = stack.pop()
        if (j == 0) {
            changes[j].add(Pair(d[j], x[j]))
        } else {
            for (change in changes[parent[j]]) {
                val g = gcd(x[j], change.second)
                if (changes[j].isEmpty() || changes[j].last().second != g) {
                    changes[j].add(Pair(change.first, g))
                }
            }
            if (changes[j].last().second != x[j]) {
                changes[j].add(Pair(d[j], x[j]))
            }
        }
        for (k in 0 until changes[j].size - 1) {
            answer += (changes[j][k + 1].first - changes[j][k].first).toLong() * changes[j][k].second
            answer %= MOD
        }
        answer += (d[j] - changes[j].last().first + 1).toLong() * changes[j].last().second
        answer %= MOD
        for (k in children[j]) {
            if (k != parent[j]) {
                parent[k] = j
                d[k] = d[j] + 1
                stack.push(k)
            }
        }
        //println("j = $j, answer = $answer")
    }
    println(answer)
}

fun gcd(a: Long, b: Long): Long {
    var alpha = max(a, b)
    var beta = min(a, b)
    while (beta != 0L) {
        alpha %= beta
        var gamma = alpha
        alpha = beta
        beta = gamma
    }
    return alpha
}