import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
        val detriments = listOf(0L) + readLine()!!.split(" ").map { it.toLong() }
        val endLadders = Array(n + 1) { mutableListOf<Ladder>() }
        val startLadders = Array(n + 1) { mutableListOf<Ladder>() }
        repeat(k) {
            val (a, b, c, d, h) = readLine()!!.split(" ").map { it.toInt() }
            val ladder = Ladder(b.toLong(), d.toLong(), h.toLong())
            startLadders[a].add(ladder)
            endLadders[c].add(ladder)
        }
        val sourceLadder = Ladder(0L, 1L, 0L)
        sourceLadder.dist = 0L
        endLadders[1].add(sourceLadder)
        val destinationLadder = Ladder(m.toLong(), 0L, 0L)
        startLadders[n].add(destinationLadder)
        for (y in 1..n) {
            endLadders[y].sortBy { it.endRoom }
            startLadders[y].sortBy { it.startRoom }
            var best = Long.MAX_VALUE / 2L
            var j = 0
            for (startLadder in startLadders[y]) {
                while (j < endLadders[y].size && endLadders[y][j].endRoom <= startLadder.startRoom) {
                    best = min(best, endLadders[y][j].dist - (detriments[y] * endLadders[y][j].endRoom))
                    j++
                }
                startLadder.dist = min(startLadder.dist, best + (detriments[y] * startLadder.startRoom) - startLadder.health)
            }
            best = Long.MAX_VALUE / 2L
            j = endLadders[y].lastIndex
            for (startLadder in startLadders[y].reversed()) {
                while (j >= 0 && endLadders[y][j].endRoom >= startLadder.startRoom) {
                    best = min(best, endLadders[y][j].dist + (detriments[y] * endLadders[y][j].endRoom))
                    j--
                }
                startLadder.dist = min(startLadder.dist, best - (detriments[y] * startLadder.startRoom) - startLadder.health)
            }
        }
        println(if (destinationLadder.dist >= Long.MAX_VALUE / 4L) "NO ESCAPE" else destinationLadder.dist)
    }
}

class Ladder(val startRoom: Long, val endRoom: Long, val health: Long) {
    var dist = Long.MAX_VALUE / 2L
}