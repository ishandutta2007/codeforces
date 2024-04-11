import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.substringAfter(' ').toInt()
        val tokenizer = StringTokenizer(readLine()!!)
        tokenizer.nextToken()
        if (n == 1) {
            println(0)
            continue
        }
        var curr = 1
        var last = tokenizer.nextToken().toInt()
        var answer = 0
        for (j in 3..n) {
            var next = tokenizer.nextToken().toInt()
            if (next == last - 1) {
                curr++
            } else {
                if (curr % 2 == 1) {
                    answer++
                }
                curr = 1
            }
            last = next
        }
        if (curr % 2 == 1 && last > 1) {
            answer++
        }
        println(answer)
    }
}