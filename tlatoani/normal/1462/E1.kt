import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toInt() }.sorted()
        var answer = 0L
        var j2 = 0
        for (j1 in 0 until n) {
            while (j2 < n && ay[j2] - ay[j1] <= 2) {
                j2++
            }
            answer += (j2 - j1 - 1).toLong() * (j2 - j1 - 2).toLong()
        }
        answer /= 2L
        out.appendln(answer)
    }
    print(out)
}