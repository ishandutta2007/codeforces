import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, x) = jin.readLine().split(" ").map { it.toInt() }
        val ws = jin.readLine().split(" ").map { it.toInt() }.sorted().toMutableList()
        if (ws.sum() == x) {
            out.appendln("NO")
        } else {
            out.appendln("YES")
            var sum = 0
            for (j in 0 until n) {
                sum += ws[j]
                if (sum == x) {
                    val a = ws[j]
                    ws[j] = ws[n - 1]
                    ws[n - 1] = a
                    break
                }
            }
            out.appendln(ws.joinToString(" "))
        }
    }
    print(out)
}