import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toLong() }
        val regular = mutableListOf<Long>()
        val important = mutableListOf<Long>()
        val memoryTokenizer = StringTokenizer(jin.readLine())
        val convenienceTokenizer = StringTokenizer(jin.readLine())
        for (j in 1L..n) {
            (if (convenienceTokenizer.nextToken() == "1") regular else important).add(memoryTokenizer.nextToken().toLong())
        }
        if (regular.sum() + important.sum() < m) {
            out.appendln(-1)
        } else {
            regular.sortDescending()
            important.sortDescending()
            var curr = 0L
            var j = 0
            while (j < regular.size && curr < m) {
                curr += regular[j]
                j++
            }
            var k = 0
            while (curr < m) {
                curr += important[k]
                k++
            }
            while (j > 0 && curr - regular[j - 1] >= m) {
                j--
                curr -= regular[j]
            }
            var answer = j + (2 * k)
            while (k < important.size) {
                curr += important[k]
                k++
                while (j > 0 && curr - regular[j - 1] >= m) {
                    j--
                    curr -= regular[j]
                }
                answer = min(answer, j + (2 * k))
            }
            out.appendln(answer)
        }
    }
    print(out)
}