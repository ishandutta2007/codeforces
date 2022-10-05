import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val squarefree = IntArray(10000001)
    squarefree[1] = 1
    for (p in 2..10000000) {
        if (squarefree[p] == 0) {
            for (k in p..10000000 step p) {
                squarefree[k] = if (squarefree[k / p] % p == 0) (squarefree[k / p] / p) else (squarefree[k / p] * p)
            }
        }
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val last = mutableMapOf<Int, Int>()
        val dpSegments = Array(n + 1) { IntArray(k + 1) { 1 } }
        val dpLast = Array(n + 1) { IntArray(k + 1) { 1 } }
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            val x = squarefree[tokenizer.nextToken().toInt()]
            val lastIndex = last[x] ?: 0
            for (d in 0..k) {
                if (dpLast[j - 1][d] > lastIndex) {
                    dpSegments[j][d] = dpSegments[j - 1][d]
                    dpLast[j][d] = dpLast[j - 1][d]
                } else {
                    dpSegments[j][d] = dpSegments[j - 1][d] + 1
                    dpLast[j][d] = j
                }
                if (d > 0 && (dpSegments[j - 1][d - 1] < dpSegments[j][d] || (dpSegments[j - 1][d - 1] == dpSegments[j][d] && dpLast[j - 1][d - 1] >= dpLast[j][d]))) {
                    dpSegments[j][d] = dpSegments[j - 1][d - 1]
                    dpLast[j][d] = dpLast[j - 1][d - 1]
                }
            }
            last[x] = j
        }
        out.appendln(dpSegments[n].min())
    }
    print(out)
}