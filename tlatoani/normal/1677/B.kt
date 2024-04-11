import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    repeat(jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        val s = jin.readLine()
        val goodRows = IntArray(n * m)
        var curr = 0
        for (j in 0 until n * m) {
            curr += s[j] - '0'
            if (j >= m) {
                curr -= s[j - m] - '0'
                goodRows[j] = goodRows[j - m]
            }
            if (curr > 0) {
                goodRows[j]++
            }
        }
        val goodColumns = IntArray(n * m)
        for (x in 0 until m) {
            var j = x
            while (j < n * m && s[j] == '0') {
                j += m
            }
            if (j < n * m) {
                goodColumns[j]++
            }
        }
        for (j in 0 until n * m) {
            if (j > 0) {
                goodColumns[j] += goodColumns[j - 1]
            }
            out.append(goodRows[j] + goodColumns[j]).append(' ')
        }
        out.appendln()
    }
    print(out)
}