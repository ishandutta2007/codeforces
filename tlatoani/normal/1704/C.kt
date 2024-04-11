import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val infected = readLine()!!.split(" ").map { it.toInt() }.sorted()
        var gaps = listOf(n + infected[0] - infected.last() - 1) + (1 until m).map { infected[it] - infected[it - 1] - 1 }
        gaps = gaps.sortedDescending()
        var answer = 0
        for ((j, gap) in gaps.withIndex()) {
            if (gap == (4 * j) + 1) {
                answer++
            } else {
                answer += max(0, gap - (4 * j) - 1)
            }
        }
        println(n - answer)
    }
}