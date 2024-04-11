import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val tokenizer = StringTokenizer(readLine()!!)
        val x = tokenizer.nextToken().toLong()
        val y = tokenizer.nextToken().toLong()
        val a = tokenizer.nextToken().toLong()
        val b = tokenizer.nextToken().toLong()
        if ((y - x) % (a + b) == 0L) {
            println((y - x) / (a + b))
        } else {
            println(-1)
        }
    }
}