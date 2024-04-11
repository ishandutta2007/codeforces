import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val joiner = StringJoiner(" ")
        for (a in 1..n) {
            for (b in a + 1..n) {
                joiner.add(when {
                    2 * (b - a) < n -> -1
                    2 * (b - a) == n -> 0
                    else -> 1
                }.toString())
            }
        }
        println(joiner)
    }
}