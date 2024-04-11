import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        jin.readLine()
        val ay = jin.readLine().split(" ").map { it.toInt() }
        val sum = ay.sum()
        if (sum > 0) {
            out.appendln("YES").appendln(ay.sortedDescending().joinToString(" "))
        } else if (sum == 0) {
            out.appendln("NO")
        } else {
            out.appendln("YES").appendln(ay.sorted().joinToString(" "))
        }
    }
    print(out)
}