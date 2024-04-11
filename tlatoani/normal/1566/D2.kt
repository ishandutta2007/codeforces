import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val sightLevels = readLine()!!.split(" ").map { it.toInt() }
        val disp = mutableMapOf<Int, ArrayDeque<Int>>()
        val people = (0 until n * m).sortedBy { sightLevels[it] }
        for (y in 0 until n) {
            for (x in m - 1 downTo 0) {
                val k = (m * y) + x
                disp.computeIfAbsent(sightLevels[people[k]]) { ArrayDeque() }.addLast(k)
            }
        }
        val rows = Array(n) { ArrayDeque<Int>() }
        var answer = 0
        for (k in 0 until n * m) {
            val seat = disp[sightLevels[k]]!!.removeFirst()
            for (alreadyThere in rows[seat / m]) {
                if (alreadyThere < seat) {
                    answer++
                }
            }
            rows[seat / m].add(seat)
        }
        println(answer)
    }
}