import kotlin.math.max
import kotlin.math.min

fun main() {
    // define chords???
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val rem = (1..2 * n).toMutableSet()
        val intervals = mutableListOf<Pair<Int, Int>>()
        repeat(k) {
            val (a, b) = readLine()!!.split(" ").map { it.toInt() }
            rem.remove(a)
            rem.remove(b)
            intervals.add(Pair(min(a, b), max(a, b)))
        }
        val sorted = rem.sorted()
        for (j in 0 until n - k) {
            intervals.add(Pair(sorted[j], sorted[j + (n - k)]))
        }
        var answer = 0
        for ((a, b) in intervals) {
            for ((c, d) in intervals) {
                if (a < c && c < b && b < d) {
                    answer++
                }
            }
        }
        println(answer)
    }
}