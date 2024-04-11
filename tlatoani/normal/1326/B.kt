import java.util.*
import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val b = IntArray(n) { tokenizer.nextToken().toInt() }
    val answer = IntArray(n)
    var x = 0
    for (j in 0 until n) {
        answer[j] = b[j] + x
        x = max(x, answer[j])
    }
    println(answer.joinToString(" "))
}