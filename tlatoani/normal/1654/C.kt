import java.util.*

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val pieces = readLine()!!.split(" ").map { it.toLong() }.sortedDescending()
        val pq = PriorityQueue<Long>(reverseOrder())
        pq.add(pieces.sum())
        var j = 0
        while (j < n) {
            if (pq.isEmpty()) {
                break
            }
            val piece = pq.remove()
            if (piece == pieces[j]) {
                j++
            } else if (piece > pieces[j]) {
                pq.add(piece / 2)
                pq.add((piece + 1) / 2)
            } else {
                break
            }
        }
        out.appendln(if (j == n) "yEs" else "nO")
    }
    print(out)
}