import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val amts = LongArray(31)
        val tokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            var k = tokenizer.nextToken().toInt()
            var log = 0
            while (k > 0) {
                log++
                k /= 2
            }
            amts[log]++
        }
        out.appendln(amts.map { (it * (it - 1L)) / 2 }.sum())
    }
    print(out)
}