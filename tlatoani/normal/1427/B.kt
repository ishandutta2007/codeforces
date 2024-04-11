import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, kv) = jin.readLine().split(" ").map { it.toInt() }
        var k = kv
        val s = jin.readLine()
        val w = s.count { it == 'W' }
        if (w + k >= n) {
            out.appendln((2 * n) - 1)
        } else if (w == 0) {
            out.appendln(max(0, (2 * k) - 1))
        } else {
            val gaps = mutableListOf<Int>()
            var j = 0
            while (s[j] != 'W') {
                j++
            }
            var answer = 1
            var gap = 0
            j++
            while (j < n) {
                if (s[j] == 'W') {
                    if (gap > 0) {
                        gaps.add(gap)
                        gap = 0
                        answer++
                    } else {
                        answer += 2
                    }
                } else {
                    gap++
                }
                j++
            }
            gaps.sort()
            answer += 2 * k
            for (gap in gaps) {
                if (k >= gap) {
                    answer++
                    k -= gap
                }
            }
            out.appendln(answer)
        }
    }
    print(out)
}