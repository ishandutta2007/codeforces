import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tokenizer = StringTokenizer(readLine()!!)
        var sum = 0L
        var answer = 0
        for (j in 1..n) {
            val a = tokenizer.nextToken().toInt()
            sum += a
            if (a == 0) {
                answer++
                sum++
            }
        }
        if (sum == 0L) {
            answer++
        }
        println(answer)
    }
}