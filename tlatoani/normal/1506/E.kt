import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val answerMin = IntArray(n)
        val answerMax = IntArray(n)
        val pqMin = PriorityQueue<Int>()
        val pqMax = PriorityQueue<Int>(reverseOrder())
        val tokenizer = StringTokenizer(jin.readLine())
        var prev = 0
        for (j in 0 until n) {
            val k = tokenizer.nextToken().toInt()
            if (k != prev) {
                answerMin[j] = k
                answerMax[j] = k
                for (l in prev + 1 until k) {
                    pqMin.add(l)
                    pqMax.add(l)
                }
                prev = k
            } else {
                answerMin[j] = pqMin.remove()
                answerMax[j] = pqMax.remove()
            }
        }
        out.appendln(answerMin.joinToString(" "))
        out.appendln(answerMax.joinToString(" "))
    }
    print(out)
}