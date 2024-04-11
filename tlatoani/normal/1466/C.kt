import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine().map { it - 'a' }
        if (s.size == 1) {
            out.appendln(0)
        } else {
            var dpNext = Array(26) { IntArray(26) }
            for (a in 0..25) {
                for (b in 0..25) {
                    if (a == b) {
                        dpNext[a][b] = 115115
                    } else {
                        dpNext[a][b] = (if (s[0] == a) 0 else 1) + (if (s[1] == b) 0 else 1)
                    }
                }
            }
            var dpPrev = dpNext
            dpNext = Array(26) { IntArray(26) }
            for (j in 2 until s.size) {
                for (b in 0..25) {
                    var best1 = if (dpPrev[0][b] < dpPrev[1][b]) 0 else 1
                    var best2 = if (dpPrev[0][b] < dpPrev[1][b]) 1 else 0
                    for (a in 2..25) {
                        if (dpPrev[a][b] < dpPrev[best1][b]) {
                            best2 = best1
                            best1 = a
                        } else if (dpPrev[a][b] < dpPrev[best2][b]) {
                            best2 = a
                        }
                    }
                    for (c in 0..25) {
                        if (c == b) {
                            dpNext[b][c] = 115115
                        } else {
                            dpNext[b][c] = (if (s[j] == c) 0 else 1) + (if (c == best1) dpPrev[best2][b] else dpPrev[best1][b])
                        }
                    }
                }
                val temp = dpPrev
                dpPrev = dpNext
                dpNext = temp
            }
            var answer = 115115
            for (b in 0..25) {
                for (c in 0..25) {
                    answer = min(answer, dpPrev[b][c])
                }
            }
            out.appendln(answer)
        }
    }
    print(out)
}