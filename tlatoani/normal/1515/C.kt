import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m, x) = jin.readLine().split(" ").map { it.toInt() }
        val heights = IntArray(m + 1)
        val answer = IntArray(n)
        val pq = PriorityQueue<Int>(compareBy { heights[it] })
        pq.addAll(1..m)
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 0 until n) {
            val block = tokenizer.nextToken().toInt()
            val k = pq.remove()
            answer[j] = k
            heights[k] += block
            pq.add(k)
        }
        out.appendln("YES")
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}