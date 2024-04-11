import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val totalTime = tokenizer.nextToken().toLong()
    tokenizer = StringTokenizer(jin.readLine())
    val x = longArrayOf(0L) + LongArray(n) { tokenizer.nextToken().toLong() }
    tokenizer = StringTokenizer(jin.readLine())
    val t = intArrayOf(0) + IntArray(n) { tokenizer.nextToken().toInt() }
    val parent = IntArray(n + 1)
    val children = Array(n + 1) { mutableListOf<Int>() }
    val birthTime = LongArray(n + 1)
    for (j in 2..n) {
        tokenizer = StringTokenizer(jin.readLine())
        parent[j] = tokenizer.nextToken().toInt()
        children[parent[j]].add(j)
        birthTime[j] = 2L * tokenizer.nextToken().toLong()
    }
    val dp = LongArray(n + 1)
    val cookiesBIT = BinaryIndexTree(1, 1000001)
    val timeBIT = BinaryIndexTree(1, 1000001)
    val stack = Stack<Int>()
    stack.push(1)
    while (stack.isNotEmpty()) {
        var a = stack.pop()
        if (a > 0) {
            birthTime[a] += birthTime[parent[a]]
            if (birthTime[a] > totalTime) {
                continue
            }
            stack.push(-a)
            cookiesBIT.update(t[a], x[a])
            timeBIT.update(t[a], t[a].toLong() * x[a])
            var lower = 0
            var upper = 1000000
            while (upper > lower) {
                val mid = (lower + upper + 1) / 2
                if (birthTime[a] + timeBIT.query(1, mid) <= totalTime) {
                    lower = mid
                } else {
                    upper = mid - 1
                }
            }
            dp[a] = cookiesBIT.query(1, upper) + min(cookiesBIT.query(upper + 1, upper + 1), (totalTime - birthTime[a] - timeBIT.query(1, upper)) / (upper + 1).toLong())
            for (b in children[a]) {
                stack.push(b)
            }
        } else {
            a *= -1
            cookiesBIT.update(t[a], -x[a])
            timeBIT.update(t[a], -t[a].toLong() * x[a])
            var best1 = 0L
            var best2 = 0L
            for (b in children[a]) {
                if (dp[b] > best1) {
                    best2 = best1
                    best1 = dp[b]
                } else if (dp[b] > best2) {
                    best2 = dp[b]
                }
            }
            if (a == 1) {
                dp[1] = max(dp[1], best1)
            } else {
                dp[a] = max(dp[a], best2)
            }
        }
    }
    println(dp[1])
}

class BinaryIndexTree(treeFrom: Int, treeTo: Int) {
    val `val`: LongArray
    val treeFrom: Int
    fun update(index: Int, delta: Long) {
        var i = index + 1 - treeFrom
        while (i < `val`.size) {
            `val`[i] += delta
            i += i and -i
        }
    }

    fun query(to: Int): Long {
        var res: Long = 0
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += `val`[i]
            i -= i and -i
        }
        return res
    }

    fun query(from: Int, to: Int): Long {
        return if (to < from) {
            0
        } else query(to) - query(from - 1)
    }

    init {
        `val` = LongArray(treeTo - treeFrom + 2)
        this.treeFrom = treeFrom
    }
}