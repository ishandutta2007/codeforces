import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var tokenizer = StringTokenizer(readLine()!!)
        val n = tokenizer.nextToken().toInt()
        val k1 = tokenizer.nextToken().toInt()
        val k2 = tokenizer.nextToken().toInt()
        var answer = ""
        tokenizer = StringTokenizer(readLine()!!)
        for (j in 1..k1) {
            if (tokenizer.nextToken().toInt() == n) {
                answer = "YES"
            }
        }
        tokenizer = StringTokenizer(readLine()!!)
        for (j in 1..k2) {
            if (tokenizer.nextToken().toInt() == n) {
                answer = "NO"
            }
        }
        println(answer)
    }
}