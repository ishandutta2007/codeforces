import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val tokenizer = StringTokenizer(jin.readLine())
        var answer1 = 0L
        var answer2 = 0L
        var m0 = 0L
        var m1 = Long.MAX_VALUE / 2L
        var curr = 0L
        for (j in 1..n) {
            val k = tokenizer.nextToken().toLong()
            if (j % 2 == 1) {
                curr -= k
                answer1 += k
            } else {
                curr += k
            }
            if (j % 2 == 1) {
                m1 = min(m1, curr)
                answer2 = max(answer2, curr - m1)
            } else {
                m0 = min(m0, curr)
                answer2 = max(answer2, curr - m0)
            }
        }
        println(answer1 + answer2)
    }
}