import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toLong()
        val tokenizer = StringTokenizer(readLine()!!)
        val weights = mutableMapOf<Int, Long>()
        var answer = 0L
        for (j in 1L..n) {
            val k = tokenizer.nextToken().toInt()
            answer += (n - j + 1L) * (weights[k] ?: 0L)
            weights[k] = (weights[k] ?: 0L) + j
        }
        println(answer)
    }
}