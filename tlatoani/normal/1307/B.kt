import java.util.*
import kotlin.math.max

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val n = line.substring(0, six).toInt()
        val x = line.substring(six + 1).toLong()
        val tokenizer = StringTokenizer(readLine()!!)
        val dists = LongArray(n) { tokenizer.nextToken().toLong() }
        if (dists.any { it == x }) {
            println(1)
        } else {
            val m = dists.max()!!
            println(max(2L, ((x - 1L) / m) + 1L))
        }
    }
}