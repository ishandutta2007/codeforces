import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tokenizer = StringTokenizer(readLine()!!)
        val answer = IntArray(n)
        var last = tokenizer.nextToken().toInt()
        for (k in 1 until n) {
            val a = tokenizer.nextToken().toInt()
            answer[k] = last - (last and a)
            last = answer[k] xor a
        }
        println(answer.joinToString(" "))
    }
}