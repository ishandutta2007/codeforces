import java.util.*
import kotlin.math.abs

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val m = line.substring(six + 1).toLong()
    if (n > m) {
        println(0)
        return
    }
    val tokenizer = StringTokenizer(readLine()!!)
    val array = LongArray(n) { tokenizer.nextToken().toLong() }
    var answer = 1L
    for (j in 0 until n) {
        for (k in j + 1 until n) {
            answer *= abs(array[j] - array[k])
            answer %= m
        }
    }
    println(answer)
}