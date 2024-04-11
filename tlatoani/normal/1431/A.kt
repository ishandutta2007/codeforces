import kotlin.math.max

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var answer = 0L
        val moneys = readLine()!!.split(" ").map { it.toLong() }.sortedDescending()
        for (j in 1..n) {
            answer = max(answer, j.toLong() * moneys[j - 1])
        }
        println(answer)
    }
}