import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class Query(val l1: Int, val l2: Int, val length: Int)

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val s = jin.readLine()
    val q = jin.readLine().toInt()
    val answer = BooleanArray(q) { true }
    val queries = Array(q) {
        val tokenizer = StringTokenizer(jin.readLine())
        val l1 = tokenizer.nextToken().toInt()
        val l2 = tokenizer.nextToken().toInt()
        val length = tokenizer.nextToken().toInt()
        Query(l1, l2, length)
    }
    for (MOD in arrayOf(998244353L, 1000000007L)) {
        for (P in arrayOf(3L, 5L, 7L)) {
            val hashes = LongArray(n + 1)
            val sums = IntArray(n + 1)
            val sum1s = IntArray(n + 1)
            for (j in 1..n) {
                if (j >= 2 && s[j - 1] == '1' && s[j - 2] == '1') {
                    hashes[j] = hashes[j - 2]
                    sums[j] = sums[j - 2]
                } else {
                    hashes[j] = ((P * hashes[j - 1]) + (s[j - 1] - '0').toLong()) % MOD
                    sums[j] = sums[j - 1] + 1
                }
                sum1s[j] = sum1s[j - 1] + (s[j - 1] - '0')
            }
            val next = IntArray(n + 1)
            next[n] = n
            for (j in n - 1 downTo 0) {
                if (s[j] == '1') {
                    next[j] = next[j + 1]
                } else {
                    next[j] = j
                }
            }
            val P_POW = LongArray(n + 2)
            P_POW[0] = 1L
            for (j in 1..n + 1) {
                P_POW[j] = (P * P_POW[j - 1]) % MOD
            }
            fun hash(x: Int, y: Int): Long {
                val xn = next[x]
                if (xn >= y) {
                    return when ((x + y) % 2) {
                        0 -> 0L
                        1 -> 1L
                        else -> -1L
                    }
                } else {
                    var res = hashes[y] - (hashes[xn] * P_POW[sums[y] - sums[xn]])
                    res %= MOD
                    if ((x + xn) % 2 == 1) {
                        res += P_POW[sums[y] - sums[xn]]
                        res %= MOD
                    }
                    res += MOD
                    res %= MOD
                    return res
                }
            }
            for (j in 0 until q) {
                if (answer[j]) {
                    val l1 = queries[j].l1
                    val l2 = queries[j].l2
                    val length = queries[j].length
                    //out.appendln("$l1 $l2 $length:")
                    answer[j] = (sum1s[l1 + length - 1] - sum1s[l1 - 1]) == (sum1s[l2 + length - 1] - sum1s[l2 - 1])
                    if (answer[j]) {
                        answer[j] = hash(l1 - 1, l1 + length - 1) == hash(l2 - 1, l2 + length - 1)
                    }
                }
            }
        }
    }
    val out = StringBuilder()
    for (j in 0 until q) {
        out.appendln(if (answer[j]) "YES" else "NO")
    }
    print(out)
}