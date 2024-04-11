import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var tokenizer = StringTokenizer(readLine()!!)
        val n = tokenizer.nextToken().toInt()
        val s = tokenizer.nextToken().toLong()
        tokenizer = StringTokenizer(readLine()!!)
        var curr = 0L
        var answer = 0
        var best = 0
        var rem = 0L
        for (j in 1..n) {
            val a = tokenizer.nextToken().toLong()
            curr += a
            if (a > rem) {
                best = j
                rem = a
            }
            if (curr - rem <= s) {
                answer = best
            }
            if (curr <= s) {
                answer = 0
            }
        }
        println(answer)
    }
}