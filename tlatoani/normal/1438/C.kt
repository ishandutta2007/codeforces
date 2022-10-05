import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, m) = jin.readLine().split(" ").map { it.toInt() }
        for (y in 1..n) {
            val tokenizer = StringTokenizer(jin.readLine())
            for (x in 1..m) {
                var k = tokenizer.nextToken().toInt()
                if ((k + y + x) % 2 != 0) {
                    k++
                }
                out.append("$k ")
            }
            out.appendln()
        }
    }
    print(out)
}