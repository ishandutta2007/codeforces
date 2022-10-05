import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val tokenizer = StringTokenizer(jin.readLine())
        val array = LongArray(n) { tokenizer.nextToken().toLong() }
        var d = 0L
        var m = array[0]
        for (j in 1 until n) {
            d = max(d, m - array[j])
            m = max(m, array[j])
        }
        var answer = 0
        while (1L shl answer <= d) {
            answer++
        }
        out.appendln(answer)
    }
    print(out)
}