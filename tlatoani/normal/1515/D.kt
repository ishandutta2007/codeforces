import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, l, r) = jin.readLine().split(" ").map { it.toInt() }
        var answer = 0
        val ds = Array(n + 1) { 0 }
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..l) {
            ds[tokenizer.nextToken().toInt()]--
        }
        for (j in 1..r) {
            ds[tokenizer.nextToken().toInt()]++
        }
        if (r > l) {
            for (j in 1..n) {
                ds[j] *= -1
            }
        }
        val pq = PriorityQueue<Int>()
        for (d in ds) {
            pq.add(d)
        }
        for (j in 1..abs(r - l) / 2) {
            answer += 2
            val d = pq.remove()
            pq.add(d + 2)
        }
        for (d in pq) {
            answer += abs(d)
        }
        answer /= 2
        out.appendln(answer)
    }
    print(out)
}