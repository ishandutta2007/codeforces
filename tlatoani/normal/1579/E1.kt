import java.util.*

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tokenizer = StringTokenizer(readLine()!!)
        val answer = ArrayDeque<Int>()
        repeat(n) {
            val k = tokenizer.nextToken().toInt()
            if (answer.isEmpty() || k < answer.first) {
                answer.addFirst(k)
            } else {
                answer.addLast(k)
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}