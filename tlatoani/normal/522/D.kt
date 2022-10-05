import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val log = IntArray(n + 1)
    for (j in 1..n) {
        if (j == 1 shl (log[j - 1] + 1)) {
            log[j] = log[j - 1] + 1
        } else {
            log[j] = log[j - 1]
        }
    }
    val left = Array(19) { IntArray(n + 1) { n + 1} }
    val right = Array(19) { IntArray(n + 1) { n + 1 } }
    val tokenizer = StringTokenizer(jin.readLine())
    val prev = mutableMapOf<Int, Int>()
    for (j in 1..n) {
        val k = tokenizer.nextToken().toInt()
        val p = prev[k]
        if (p != null) {
            left[0][j] = j - p
            right[0][p] = j - p
        }
        prev[k] = j
    }
    for (e in 1..18) {
        val b = 1 shl (e - 1)
        for (j in 1..n - (1 shl e) + 1) {
            left[e][j] = min(left[e - 1][j], left[e - 1][j + b])
            right[e][j] = min(right[e - 1][j], right[e - 1][j + b])
        }
    }
    fun queryLeft(from: Int, to: Int): Int {
        val e = log[to - from + 1]
        return min(left[e][from], left[e][to - (1 shl e) + 1])
    }
    fun queryRight(from: Int, to: Int): Int {
        val e = log[to - from + 1]
        return min(right[e][from], right[e][to - (1 shl e) + 1])
    }
    val out = StringBuilder()
    for (j in 1..m) {
        val (l, r) = jin.readLine().split(" ").map { it.toInt() }
        var res = 1
        while (res <= r - l) {
            val length = (r - l - res) / 2
            res = min(queryRight(l, l + length), queryLeft(r - length, r))
            if (l + length + res <= r) {
                break
            }
        }
        out.appendln(if (res <= r - l) res else -1)
    }
    print(out)
}