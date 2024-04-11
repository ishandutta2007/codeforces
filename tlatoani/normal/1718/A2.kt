import java.util.*
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val same = mutableMapOf<Int, Int>()
        same[0] = 0
        val tokenizer = StringTokenizer(readLine()!!)
        var curr = 0
        var prev = 0
        for (j in 1..n) {
            curr = curr xor tokenizer.nextToken().toInt()
            var here = prev + 1
            if (curr in same) {
                val prevSame = same[curr]!!
                here = min(here, prevSame + j - 1)
            }
            same[curr] = here - j
            prev = here
        }
        println(prev)
    }
}