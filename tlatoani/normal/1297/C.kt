import java.util.*
import kotlin.math.abs

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val answer = IntArray(n)
        val tokenizer = StringTokenizer(readLine()!!)
        var sum = 0
        var ix = -1
        var toChange = 10001
        for (j in 0 until n) {
            var a = tokenizer.nextToken().toInt()
            if (a >= 0) {
                answer[j] = 1
                sum += a
            }
            if (a != 0 && abs(a) < toChange) {
                ix = j
                toChange = abs(a)
            }
        }
        answer[ix] = 1 - answer[ix]
        sum -= toChange
        println(sum)
        println(answer.joinToString(""))
    }
}