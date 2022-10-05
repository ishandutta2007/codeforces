import java.util.*
import kotlin.math.abs

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val slimes = Array(n) { tokenizer.nextToken().toLong() }
    if (n == 1) {
        println(slimes[0])
        return
    }
    if (slimes.all { it >= 0 }) {
        println(slimes.sum() - (2L * slimes.min()!!))
    } else if (slimes.all { it <= 0 }) {
        println(-slimes.sum() + (2L * slimes.max()!!))
    } else {
        var answer = 0L
        for (slime in slimes) {
            answer += abs(slime)
        }
        println(answer)
    }
}