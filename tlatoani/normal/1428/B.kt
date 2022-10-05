import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        var s = jin.readLine()
        s += s
        val right = IntArray(2 * n) { it }
        for (j in (2 * n) - 2 downTo 0) {
            if (s[j] != '<') {
                right[j] = right[j + 1]
            }
        }
        val left = IntArray(2 * n) { it }
        for (j in 1 until 2 * n) {
            if (s[j - 1] != '>') {
                left[j] = left[j - 1]
            }
        }
        var answer = 0
        for (j in 0 until n) {
            if (s[j] == '-' || s[j + n - 1] == '-' || right[j] >= j + n || left[j + n] <= j) {
                answer++
            }
        }
        out.appendln(answer)
    }
    print(out)
}