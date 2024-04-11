import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val places = Array(n + 1) { mutableListOf(0) }
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            places[tokenizer.nextToken().toInt()].add(j)
        }
        val answer = IntArray(n + 2) { n + 1 }
        for (j in n downTo 1) {
            places[j].add(n + 1)
            var k = 0
            var last = places[j][0]
            for (ix in places[j]) {
                k = max(k, ix - last)
                last = ix
            }
            answer[k] = j
        }
        for (k in 2..n) {
            answer[k] = min(answer[k - 1], answer[k])
        }
        for (k in 1..n) {
            if (answer[k] == n + 1) {
                answer[k] = -1
            }
        }
        out.appendln(answer.toList().subList(1, n + 1).joinToString(" "))
    }
    print(out)
}