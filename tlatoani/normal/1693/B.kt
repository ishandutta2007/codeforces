import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val parents = listOf(0, 0) + readLine()!!.split(" ").map { it.toInt() }
        val constraints = listOf(listOf<Long>()) + List(n) { readLine()!!.split(" ").map { it.toLong() } }
        val below = LongArray(n + 1)
        var answer = 0
        for (a in n downTo 1) {
            val (l, r) = constraints[a]
            val here = if (below[a] >= l) {
                min(below[a], r)
            } else {
                answer++
                r
            }
            below[parents[a]] += here
        }
        println(answer)
    }
}