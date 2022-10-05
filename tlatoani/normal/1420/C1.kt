import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, q) = jin.readLine().split(" ").map { it.toInt() }
        val strengths = (listOf(0) + jin.readLine().split(" ").map { it.toInt() }).toIntArray()
        fun value(j: Int): Long {
            return if (j !in 1..n) {
                0
            } else if ((j == 1 || strengths[j] > strengths[j - 1]) && (j == n || strengths[j] > strengths[j + 1])) {
                strengths[j].toLong()
            } else if (j != 1 && strengths[j] < strengths[j - 1] && j != n && strengths[j] < strengths[j + 1]) {
                -strengths[j].toLong()
            } else {
                0
            }
        }
        var answer = 0L
        for (j in 1..n) {
            answer += value(j)
        }
        out.appendln(answer)
        for (j in 1..q) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            if (a != b) {
                answer -= value(a - 1)
                answer -= value(a)
                answer -= value(a + 1)
                if (a + 1 < b - 1) {
                    answer -= value(b - 1)
                }
                if (a + 1 < b) {
                    answer -= value(b)
                }
                answer -= value(b + 1)
                val x = strengths[a]
                val y = strengths[b]
                strengths[a] = y
                strengths[b] = x
                answer += value(a - 1)
                answer += value(a)
                answer += value(a + 1)
                if (a + 1 < b - 1) {
                    answer += value(b - 1)
                }
                if (a + 1 < b) {
                    answer += value(b)
                }
                answer += value(b + 1)
            }
            out.appendln(answer)
        }
    }
    print(out)
}