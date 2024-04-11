import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ws = listOf(0L) + jin.readLine().split(" ").map { it.toLong() }
        val degree = IntArray(n + 1)
        for (j in 2..n) {
            val (a, b) = jin.readLine().split(" ").map { it.toInt() }
            degree[a]++
            degree[b]++
        }
        val disp = mutableListOf<Long>()
        for (a in 1..n) {
            for (j in 2..degree[a]) {
                disp.add(ws[a])
            }
        }
        disp.sortDescending()
        var curr = ws.sum()
        for (j in 1..n - 1) {
            if (j >= 2) {
                curr += disp[j - 2]
            }
            out.append(curr).append(' ')
        }
        out.appendln()
    }
    print(out)
}