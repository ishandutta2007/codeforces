import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        var zeros = xs.count { it == 0}
        var ones = 0
        var answer = zeros
        for (x in xs) {
            when (x) {
                0 -> zeros--
                1 -> ones++
            }
            answer = min(answer, max(zeros, ones))
        }
        println(answer)
    }
}