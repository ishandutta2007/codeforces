import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val answer = mutableListOf<Int>()
    for (j in 1..n) {
        val a = tokenizer.nextToken().toInt()
        answer.remove(a)
        answer.add(a)
    }
    println(answer.size)
    println(answer.joinToString(" "))
}