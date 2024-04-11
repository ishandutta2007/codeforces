import java.util.*

const val N = 500002

fun main() {
    val n = readLine()!!.toInt()

    val notCaptured = Array(N) { TreeSet<Int>() }
    val pawns = Array(n) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        notCaptured[y].add(x)
        x to y
    }
    pawns.sortWith { a, b -> if (a.second == b.second) b.first - a.first else a.second - b.second }

    for ((x, y) in pawns) {
        for (yNxt in arrayOf(y - 1, y + 1)) {
            val xNxt = notCaptured[yNxt].higher(x)
            if (xNxt != null) {
                notCaptured[yNxt].remove(xNxt)
                break
            }
        }
    }

    println(notCaptured.sumOf { it.size })
}