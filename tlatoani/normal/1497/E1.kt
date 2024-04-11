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
        val dpSegments = IntArray(k + 1) { 1 }
        val dpLast = IntArray(k + 1) { 1 }
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            val x = squarefree[tokenizer.nextToken().toInt()]
            val lastIndex = last[x] ?: 0
            var updated = false
            for (d in 0..k) {
                if (updated) {
                    updated = false
                } else if (dpLast[d] <= lastIndex) {
                    if (d < k && (dpSegments[d] < dpSegments[d + 1] || (dpSegments[d] == dpSegments[d + 1] && dpLast[d] >= dpLast[d + 1]))) {
                        dpSegments[d + 1] = dpSegments[d]
                        dpLast[d + 1] = dpLast[d]
                        updated = true
                    }
                    dpSegments[d]++
                    dpLast[d] = j
                }
            }
            last[x] = j
        }
        out.appendln(dpSegments.min())
    }
    print(out)
}