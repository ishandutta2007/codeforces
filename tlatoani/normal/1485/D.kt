import java.util.*

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    for (y in 1..n) {
        val tokenizer = StringTokenizer(readLine()!!)
        for (x in 1..m) {
            val k = tokenizer.nextToken().toInt()
            print("${720720 - (if ((x + y) % 2 == 0) 0 else (k * k * k * k))} ")
        }
        println()
    }
}